#ifndef THEMES_HPP
#define THEMES_HPP
#include "json_manipulator.hpp"

    class Themes{
        Element_manipulator *_current_element;
        Element_manipulator *get_main_node();
        Element_manipulator *get_mistakes_node();
        Element_manipulator *get_planes_node();


    public:
        void process_data();
        void send_data();
        Themes();
   };

#endif // THEMES_HPP
