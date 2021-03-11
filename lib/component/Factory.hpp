/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <yaml-cpp/node/node.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "engine/debug.hpp"
#include "ecs/Coordinator.hpp"
#include "component/window.hpp"
#include "component/sprite.hpp"
#include "component/movable.hpp"
#include "component/transform.hpp"
#include "component/animate.hpp"
#include "component/clickable.hpp"
#include "component/drawable.hpp"
#include "component/label.hpp"
#include "component/moving.hpp"
#include "component/shoot.hpp"
#include "component/collision.hpp"
#include "component/spawner.hpp"

/** @brief Contains the components for the Entity Component System */
namespace component {

/** @brief The Factory class to create all components when needed */
class Factory {
    public:
        
        /// @brief The constructor of the Factory
        Factory();

        /// @brief The destructor of the Factory
        ~Factory();

        /** @brief Initialize and create the window component 
         * 
         *  @param coord The coordinator of the ecs
         *  @param entity The entity that will contain the new component
         *  @param node A node of a YAML file (configuration file)
        */
        static void create_window(ecs::Coordinator &coord, const ecs::Entity entity, const YAML::Node &node)
        {
            component::window &cwindow = coord.add_component<component::window>(entity);
            std::string title = "default";
            bool is_fullscreen = false;
            int width = 1024;
            int height = 600;

            cwindow.window = std::make_shared<sf::RenderWindow>();
            if (node["width"])
                width = node["width"].as<unsigned int>();
            if (node["height"])
                height = node["height"].as<unsigned int>();
            if (node["fullscreen"])
                is_fullscreen = node["fullscreen"].as<bool>();
            if (node["title"])
                title = node["title"].as<std::string>();
            sf::VideoMode size_window = sf::VideoMode(width, height);
            cwindow.window->create(size_window, title.c_str(), ((is_fullscreen == false) ? sf::Style::Default : sf::Style::Fullscreen));
            
            if (node["icon"]) {
                const std::string icon = node["icon"].as<std::string>();
                cwindow.icon.loadFromFile(icon);
                cwindow.window->setIcon(175, 175, cwindow.icon.getPixelsPtr());
            }
            if (node["sound"]) {
                cwindow.music = std::make_shared<sf::Music>();
                cwindow.music->openFromFile(node["sound"].as<std::string>());
                cwindow.music->play();
                cwindow.music->setLoop(true);
            }
        }

        /** @brief Initialize and create the drawable component 
         * 
         *  @param coord The coordinator of the ecs
         *  @param entity The entity that will contain the new component
         *  @param draw A pointer to the element to draw
        */
        static void create_drawable(ecs::Coordinator &coord, const ecs::Entity entity, std::shared_ptr<sf::Drawable> draw)
        {
            component::drawable &cdrawable = coord.add_component<component::drawable>(entity);
            cdrawable.draw = draw;
        }

        /** @brief Initialize and create the sprite component 
         * 
         *  @param coord The coordinator of the ecs
         *  @param entity The entity that will contain the new component
         *  @param node A node of a YAML file (configuration file)
        */
        static void create_sprite(ecs::Coordinator &coord, const ecs::Entity entity, const YAML::Node &node)
        {
            component::sprite &csprite = coord.add_component<component::sprite>(entity);
            csprite.scale = sf::Vector2f(1, 1);
            if (node["texture"])
                csprite.texture.loadFromFile(node["texture"].as<std::string>());
            if (node["scale_x"])
                csprite.scale.x = node["scale_x"].as<float>();
            if (node["scale_y"])
                csprite.scale.y = node["scale_y"].as<float>();
            csprite.as_texture_rect = false;
            csprite.rect = {0, 0, 0, 0};
            if (node["rect_x"])
                csprite.rect.left = node["rect_x"].as<int>();
            if (node["rect_y"])
                csprite.rect.top = node["rect_y"].as<int>();
            if (node["rect_width"])
                csprite.rect.width = node["rect_width"].as<int>();
            if (node["rect_height"])
                csprite.rect.height = node["rect_height"].as<int>();
            if (node["sound"]) {
                csprite.music = std::make_shared<sf::Music>();
                csprite.music->openFromFile(node["sound"].as<std::string>());
                csprite.music->play();
            }
            csprite.sprite = std::make_shared<sf::Sprite>();
            if (csprite.rect.left != 0 || csprite.rect.top != 0 || csprite.rect.width != 0 || csprite.rect.height != 0) {
                csprite.as_texture_rect = true;
                csprite.sprite->setTextureRect(csprite.rect);
            }
            csprite.sprite->setTexture(csprite.texture);
            csprite.sprite->setScale(csprite.scale);
            create_drawable(coord, entity, csprite.sprite);
        }

        /** @brief Initialize and create the label component 
         * 
         *  @param coord The coordinator of the ecs
         *  @param entity The entity that will contain the new component
         *  @param node A node of a YAML file (configuration file)
        */
        static void create_label(ecs::Coordinator &coord, const ecs::Entity entity, const YAML::Node &node)
        {
            component::label &clabel = coord.add_component<component::label>(entity);
            if (node["font"])
                clabel.font.loadFromFile(node["font"].as<std::string>());
            clabel.text = std::make_shared<sf::Text>();
            clabel.text->setFont(clabel.font);
            if (node["text"])
                clabel.text->setString(node["text"].as<std::string>());
            if (node["font_size"])
                clabel.text->setCharacterSize(node["font_size"].as<int>());
            create_drawable(coord, entity, clabel.text);
        }

        /** @brief Initialize and create the transform component 
         * 
         *  @param coord The coordinator of the ecs
         *  @param entity The entity that will contain the new component
         *  @param node A node of a YAML file (configuration file)
        */
        static void create_transform(ecs::Coordinator &coord, const ecs::Entity entity, const YAML::Node &node)
        {
            component::transform &ctransform = coord.add_component<component::transform>(entity);
            float x = 0;
            float y = 0;
            int rot = 0;
            float width = 0;
            float height = 0;
            ctransform.dir = {0, 0};

            if (node["x"])
                x = node["x"].as<float>();
            if (node["y"])
                y  = node["y"].as<float>();
            if (node["rot"])
             rot = node["rot"].as<int>();
            if (node["width"])
                width = node["width"].as<float>();
            if (node["height"])
                height = node["height"].as<float>();
            ctransform.pos = sf::Vector2f(x, y);
            ctransform.rot = rot;
            ctransform.size = sf::Vector2f(width, height);
        }

        /** @brief Initialize and create the movable component 
         * 
         *  @param coord The coordinator of the ecs
         *  @param entity The entity that will contain the new component
         *  @param node A node of a YAML file (configuration file)
        */
        static void create_movable(ecs::Coordinator &coord, const ecs::Entity entity, const YAML::Node &node)
        {
            component::movable &cmovable = coord.add_component<component::movable>(entity);
            cmovable.move_up = sf::Keyboard::Z;
            cmovable.move_down = sf::Keyboard::S;
            cmovable.move_left = sf::Keyboard::Q;
            cmovable.move_right = sf::Keyboard::D;
            cmovable.speed = 20;
            if (node["speed"])
                cmovable.speed = node["speed"].as<float>();
        }

        /** @brief Initialize and create the animate component 
         * 
         *  @param coord The coordinator of the ecs
         *  @param entity The entity that will contain the new component
         *  @param node A node of a YAML file (configuration file)
        */
        static void create_animate(ecs::Coordinator &coord, const ecs::Entity entity, const YAML::Node &node)
        {
            component::animate &canimate = coord.add_component<component::animate>(entity);
            canimate.current_frame = 0;
            if (node["frame_time"])
                canimate.frame_time = node["frame_time"].as<float>();
            canimate.max_frames = 0;
            if (node["total_frames"])
                canimate.max_frames = node["total_frames"].as<int>();
        }

        /** @brief Initialize and create the clickable component 
         * 
         *  @param coord The coordinator of the ecs
         *  @param entity The entity that will contain the new component
         *  @param node A node of a YAML file (configuration file)
        */
        static void create_clickable(ecs::Coordinator &coord, const ecs::Entity entity, const YAML::Node &node)
        {
            component::clickable &cclickable = coord.add_component<component::clickable>(entity);
            if (node["signal"])
                cclickable.event_name = node["signal"].as<std::string>();
            cclickable.music = std::make_shared<sf::Music>();
            if (node["sound"]) {
                if (!cclickable.music->openFromFile(node["sound"].as<std::string>()))
                    std::cout << "error " << node["sound"].as<std::string>() << " " << node["signal"].as<std::string>() << std::endl;
            }
        }

        /** @brief Initialize and create the moving component 
         * 
         *  @param coord The coordinator of the ecs
         *  @param entity The entity that will contain the new component
         *  @param node A node of a YAML file (configuration file)
        */
        static void create_moving(ecs::Coordinator &coord, const ecs::Entity entity, const YAML::Node &node)
        {
            component::moving &cmove = coord.add_component<component::moving>(entity);
            cmove.loop = false;
            cmove.free_on_completion = false;

            if (node["start_x"])
                cmove.start.x = node["start_x"].as<float>();
            if (node["start_y"])
                cmove.start.y = node["start_y"].as<float>();
            if (node["dest_x"])
                cmove.dest.x = node["dest_x"].as<float>();
            if (node["dest_y"])
                cmove.dest.y = node["dest_y"].as<float>();
            if (node["move_x"])
                cmove.move.x = node["move_x"].as<float>();
            if (node["move_y"])
                cmove.move.y = node["move_y"].as<float>();
            if (node["duration"]) {
                float duration = node["duration"].as<float>();
                cmove.move.x = (cmove.dest.x - cmove.start.x) / duration;
                cmove.move.y = (cmove.dest.y - cmove.start.y) / duration;
            }
            if (node["loop"])
                cmove.loop = node["loop"].as<bool>();
            if (node["free_on_completion"])
                cmove.free_on_completion = node["free_on_completion"].as<bool>();
        }

        static void create_shoot(ecs::Coordinator &coord, const ecs::Entity entity, const YAML::Node &node)
        {
            component::shoot &cshoot = coord.add_component<component::shoot>(entity);
            cshoot.index = 0;

            if (node["template"])
                cshoot.entity_template = node["template"];
            if (node["delay"])
                cshoot.delay = node["delay"].as<float>();
        }

        static void create_collision(ecs::Coordinator &coord, const ecs::Entity entity, const YAML::Node &node)
        {
            component::collision &ccollision = coord.add_component<component::collision>(entity);
            ccollision.shape = {0, 0, 0, 0};
            ccollision.layer = 0;
            ccollision.bitmask = 0;

            if (node["rect_x"])
                ccollision.shape.left = node["rect_x"].as<int>();
            if (node["rect_y"])
                ccollision.shape.top = node["rect_y"].as<int>();
            if (node["rect_width"])
                ccollision.shape.width = node["rect_width"].as<int>();
            if (node["rect_height"])
                ccollision.shape.height = node["rect_height"].as<int>();
            if (node["layer"])
                ccollision.layer = node["layer"].as<int>();
            if (node["bitmask"])
                ccollision.bitmask = node["bitmask"].as<int>();
        }

        static void create_spawner(ecs::Coordinator &coord, const ecs::Entity entity, const YAML::Node &node)
        {
            component::spawner &cspawner = coord.add_component<component::spawner>(entity);
            cspawner.index = 0;

            if (node["waves"]) {
                YAML::Node waves = node["waves"];
                for (YAML::const_iterator it = waves.begin(); it != waves.end(); it++) {
                    if (it->second["delay"] && it->second["file"]) {
                        cspawner.wave_time.push_back(it->second["delay"].as<float>());
                        cspawner.wave_file.push_back(it->second["file"].as<std::string>());
                    }
                }
            }
        }

    protected:
    private:
};

}

#endif /* !FACTORY_HPP_ */
