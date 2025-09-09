//
// Created by AlexanderSYN on 09.09.2025.
//

#include "../../helper_header/console/color_console.h"

std::string ColorConsole::choice_color(std::string user_input)
{
    if (user_input.substr(6) == "dark_red")
    {
        ColCons::set_red_color_console();
        return "The color changed to dark red";
    }
    else if (user_input.substr(6) == "red")
    {
        ColCons::set_LightRed_color_console();
        return "The color changed to red!";
    }

    else if (user_input.substr(6) == "brown")
    {
        ColCons::set_Brown_color_console();
        return "The color changed to brown!";
    }

    else if (user_input.substr(6) == "dark_cyan")
    {
        ColCons::set_cyan_color_console();
        return "The color changed to dark cyan!";
    }
    else if (user_input.substr(6) == "cyan")
    {
        ColCons::set_LightCyan_color_console();
        return "The color changed to cyan!";
    }

    else if (user_input.substr(6) == "dark_gray")
    {
        ColCons::set_DarkGray_console();
        return "The color changed to dark_gray!";
    }
    else if (user_input.substr(6) == "gray")
    {
        ColCons::set_LightGray_color_console();
        return "The color changed to gray!";
    }

    else if (user_input.substr(6) == "dark_blue")
    {
        ColCons::set_blue_color_console();
        return "The color changed to dark_blue!";
    }
    else if (user_input.substr(6) == "blue")
    {
        ColCons::set_LightBlue_color_console();
        return "The color changed to blue!";
    }

    else if (user_input.substr(6) == "dark_green")
    {
        ColCons::set_green_color_console();
        return "The color changed to dark green!";
    }
    else if (user_input.substr(6) == "green")
    {
        ColCons::set_LightGreen_color_console();
        return "The color changed to green!";
    }

    else if (user_input.substr(6) == "magenta")
    {
        ColCons::set_magenta_color_console();
        return "The color changed to magenta!";
    }

    else if (user_input.substr(6) == "yellow")
    {
        ColCons::set_yellow_color_console();
        return "The color changed to yellow!";
    }

    else if (user_input.substr(6) == "default" || user_input.substr(6) == "def"
        || user_input.substr(6) == "white")
    {
        ColCons::set_white_color_console();
        return "The color changed to white!";
    }

    else if (user_input.substr(6) == "help")
    {
        std::cout << "_____available colors that you can use_____" << std::endl;

        ColCons::set_red_color_console();
        std::cout << "this text is dark red in color -> dark_red" << std::endl;
        ColCons::set_LightRed_color_console();
        std::cout << "this text is red in color -> red" << std::endl;

        ColCons::set_green_color_console();
        std::cout << "this text is dark green in color -> dark_green" << std::endl;
        ColCons::set_LightGreen_color_console();
        std::cout << "this text is green in color -> green" << std::endl;

        ColCons::set_blue_color_console();
        std::cout << "this text is dark blue in color -> dark_blue" << std::endl;
        ColCons::set_LightBlue_color_console();
        std::cout << "this text is blue in color -> blue" << std::endl;

        ColCons::set_cyan_color_console();
        std::cout << "this text is dark cyan in color -> dark_cyan" << std::endl;
        ColCons::set_LightCyan_color_console();
        std::cout << "this text is cyan in color -> cyan" << std::endl;

        ColCons::set_Brown_color_console();
        std::cout << "this text is brown in color -> brown" << std::endl;

        ColCons::set_DarkGray_console();
        std::cout << "this text is dark gray in color -> dark_gray" << std::endl;
        ColCons::set_LightGray_color_console();
        std::cout << "this text is gray in color -> gray" << std::endl;

        ColCons::set_magenta_color_console();
        std::cout << "this text is magenta in color -> magenta" << std::endl;

        ColCons::set_yellow_color_console();
        std::cout << "this text is yellow in color -> yellow" << std::endl;

        ColCons::set_white_color_console();
        std::cout << "this text is white in color -> white / default / def" << std::endl;
        return "___________________________________________";
    }
    else {
        return "error - the command did not find the color ... maybe you need help write -> help color";
    }



}



HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void ColCons::set_red_color_console()
{
    SetConsoleTextAttribute(hConsole, Red);
}

void ColCons::set_Brown_color_console()
{
    SetConsoleTextAttribute(hConsole, Brown);
}

void ColCons::set_cyan_color_console()
{
    SetConsoleTextAttribute(hConsole, Cyan);
}

void ColCons::set_DarkGray_console()
{
    SetConsoleTextAttribute(hConsole, DarkGray);
}

void ColCons::set_LightBlue_color_console()
{
    SetConsoleTextAttribute(hConsole, LightBlue);
}

void ColCons::set_LightCyan_color_console()
{
    SetConsoleTextAttribute(hConsole, LightCyan);
}

void ColCons::set_LightGray_color_console()
{
    SetConsoleTextAttribute(hConsole, LightGray);
}

void ColCons::set_LightGreen_color_console()
{
    SetConsoleTextAttribute(hConsole, LightGreen);
}

void ColCons::set_LightRed_color_console()
{
    SetConsoleTextAttribute(hConsole, LightRed);
}

void ColCons::set_yellow_color_console()
{
    SetConsoleTextAttribute(hConsole, Yellow);
}

void ColCons::set_magenta_color_console()
{
    SetConsoleTextAttribute(hConsole, Magenta);
}

void ColCons::set_green_color_console()
{
    SetConsoleTextAttribute(hConsole, Green);
}

void ColCons::set_blue_color_console()
{
    SetConsoleTextAttribute(hConsole, Blue);
}

void ColCons::set_white_color_console()
{
    SetConsoleTextAttribute(hConsole, White);
}
