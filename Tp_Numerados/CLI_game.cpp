#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
#include <conio.h> //_getch()
#else
#include <termios.h>
#include <unistd.h>
#endif

class validator
{
private:
    std::string input;

public:
    validator() : input("") {}
    bool validateOption(std::string option)
    {
        if (option.length() != 1)
        {
            return false;
        }
        if (option.front() == 'a' || option.front() == 'b' || option.front() == 'c' || option.front() == 'd' || option.front() == 'e')
        {
            return true;
        }
        return false;
    }
};

class UI
{
private:
    const std::string tabs;
    std::string menuOption;

public:
    UI() : tabs("                                  "), menuOption("") {}
    std::string getMenuOption()
    { // Unique getter of the code
        return menuOption;
    }
    void setMenuOption()
    { // Unique setter of the code
        std::cin >> menuOption;
    }
    void clear()
    {
#ifdef _WIN32
        std::cout << "\033[H\033[J";
#else
        system("clear");
#endif
    }
    void wait()
    {
        std::cout << tabs << "\n\n                                                Toque alguna tecla para continuar..." << std::flush;
#ifdef _WIN32
        _getch();
#else
        termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        char ch;
        read(STDIN_FILENO, &ch, 1);

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif
    }
    void showTraining()
    {
        for (int i = 0; i < 20; ++i)
        {
            clear();
            int rep = i / 2 + 1;
            std::cout << "\033[38;5;159m";
            if (i % 2 == 0)
            {
                std::cout << tabs << "                                            ..@.::   @..                                            \n";
                std::cout << tabs << "                                          @@  @:::...@  @@                                          \n";
                std::cout << tabs << "                                        %:               .@.                                        \n";
                std::cout << tabs << "                                       @.    ... .  .      :@                                       \n";
                std::cout << tabs << "                                       @.    @@@@@@@@@@   #-@                                       \n";
                std::cout << tabs << "                                     :@     -@. .    .@.     @.                                     \n";
                std::cout << tabs << "                                   .@+   +%+=@@@@@@%%%@@@@+  .+%                                    \n";
                std::cout << tabs << "                                     %=..@*              @* -=@                                     \n";
                std::cout << tabs << "                                      ... @  . @    . .  @  @.                                      \n";
                std::cout << tabs << "                                       @%=@  @@@    @@.  @..@                                       \n";
                std::cout << tabs << "                                        @@@  @@@    @@.  @%@                                        \n";
                std::cout << tabs << "                                        @@@@           =@@@@                                        \n";
                std::cout << tabs << "                                     @@@@@@@%@@@@@@@@@@@@#@@@@@                                     \n";
                std::cout << tabs << "                                   %@@@@@@=.=.    ::%@%@@@@@@@@@                                    \n";
                std::cout << tabs << "                                  @@@@@@@@@*.*   ..*@@@@%@@@@@@@@                                   \n";
                std::cout << tabs << "                                 .@  @@@@@@@=* .  :@@@:@@@@@@@=-.                                   \n";
                std::cout << tabs << "                                 @      @@@@*@@**@@*@@@@@@@:     ::                                 \n";
                std::cout << tabs << "                                #.      @@#%.@@: @@ %#@@@@@:      *+                                \n";
                std::cout << tabs << "                                @      @  =% @@. @@:=#@@@  @@     **                                \n";
                std::cout << tabs << "                               @    @@@@@@@@@%:@ == %%@@@@@@@@@=    @                               \n";
                std::cout << tabs << "              @ -@  @         @#   @=     @@@@@@@@@@@@@@@@     @-   %.        %%%@@%#@              \n";
                std::cout << tabs << "             @@ :@ :@@        @    @@      @@@@@@@@@@@@@       @     .       *@.=@@+%@@             \n";
                std::cout << tabs << "             .@ :: =@@        @:   @@     ::@@@@@@@@@@@@ -     @=    .       *   @@.=@@             \n";
                std::cout << tabs << "           @@.@ ::. @@%.     %@@@@@:.@    .@@@@@@@@@@@@@@     @.@@@@@@      +%: .@@  @@+            \n";
                std::cout << tabs << "        @@@@  @ :: =@@=@@@@@@@     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@= .@@  @@.@@@         \n";
                std::cout << tabs << "        @.:@@.@ ::  @@*@@@@@@@ = @ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ :  -@@@@@@@= : @@:@@@: ..         \n";
                std::cout << tabs << "           @@@@ :*  @@@*               @@@@             =:*=@               @@*. @@..@@@            \n";
                std::cout << tabs << "             +@.%@#+@@               @+*=*%=@          @ :    @              *=@@@@::@@             \n";
                std::cout << tabs << "             @@.:@=%@@              %  .... @          @ .   . @             *@@@@@. @@             \n";
                std::cout << tabs << "              @@@@@@@                                                         %@@@@@@@              \n";
            }
            else
            {
                std::cout << tabs << "                                      @@@@@@                                    \n";
                std::cout << tabs << "                                  @@       @ @@                                 \n";
                std::cout << tabs << "                                 @  -- #  # #  @                                \n";
                std::cout << tabs << "                                @    @@@@@@@    @                               \n";
                std::cout << tabs << "                                @%=@@@ @  @ @@@ -=                              \n";
                std::cout << tabs << "                              @   @           @   @                             \n";
                std::cout << tabs << "                               @@ @%%%@###%%%#@ :@#                             \n";
                std::cout << tabs << "                                @@@  @@   @@  @                                 \n";
                std::cout << tabs << "                                 @@@          @.                                \n";
                std::cout << tabs << "                                 @==@@*#####@ #@                                \n";
                std::cout << tabs << "                             @@@@@@@@@  @  @@@@@@@@@                            \n";
                std::cout << tabs << "                            @.   @@@@@@@@@@@@@@@%   :                           \n";
                std::cout << tabs << "                            @    @@.#@= @@ @  @@                                \n";
                std::cout << tabs << "                           *    @ @%@@@*@@#@#@@ @    @                          \n";
                std::cout << tabs << "                              -+   @@@@@@@@@@@@   =                             \n";
                std::cout << tabs << "            @ @@ @        @   @   @=+     :@ #    @   @           . #.          \n";
                std::cout << tabs << "           :  @  :        @  .    @@@@@@@@@@@@@    @  @                         \n";
                std::cout << tabs << "           - =@ @@        %  @   @@*#@@+@@.@:-@@   @             %              \n";
                std::cout << tabs << "       @@@.@@ @@ #@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@   %@@@@@@+-% -  * @@@      \n";
                std::cout << tabs << "       @@@ +  @  *+@     @@@@@  @@@@@@@@@@@@@@@@@  @@@@@     : -  @  - @@@      \n";
                std::cout << tabs << "           @@ @@ @              @@@@@@@@  @@@@@@@@             @ =@ %@          \n";
                std::cout << tabs << "           @% @* @              @@@@%*@   @@%@@@@@             @  = .@          \n";
                std::cout << tabs << "            @@@@@@              @    @                          @@@@@.          \n";
                std::cout << tabs << "                                  @ @       :    @                              \n";
                std::cout << tabs << "                               @    .                                           \n";
                std::cout << tabs << "                               @             @                                  \n";
                std::cout << tabs << "                               @@@@@          @@@@                              \n";
                std::cout << tabs << "                               @  :           @                                 \n";
                std::cout << tabs << "                              @@@@@           @@@@@                             \n";
                std::cout << tabs << "                             @    =                @                            \n";
                std::cout << tabs << "                            @@@@@@@           @@@@@@@                           \n";
                std::cout << "                                                                                \n";
            }
            std::cout << "\033[0m";
            std::cout << "\033[38;5;39m";
            std::cout << tabs << "                                                    █▀█ █▀▀ █▀█ █▀▀ ▀█▀ █ █▀▀ █ █▀█ █▄░█ █▀▀ █▀ \n";
            std::cout << tabs << "             1 0 R e p s = [+ 1 0  F U E R Z A]     █▀▄ ██▄ █▀▀ ██▄ ░█░ █ █▄▄ █ █▄█ █░▀█ ██▄ ▄█ " << rep << "\n";
            std::cout << "\033[0m";
            std::this_thread::sleep_for(std::chrono::milliseconds(380));
        }
    }
    void showMission()
    {
        const int totalFrames = 100;
        for (int i = 0; i < totalFrames; ++i)
        {
            clear();
            std::string m(i / 2, ' '); // Avance físico
            int anim = i % 8;

            std::cout << "━━━ 🌲 ＭＩＳＩÓＮ ＥＮ ＥＬ ＢＯＳＱＵＥ 🌲 ━━━ D i s t a n c i a: " << i << "/1 0 0 mts\n\n";

            std::cout << "\n\n\033[32m   ^^        ^^        ^^        ^^        ^^        ^^        ^^        ^^        ^^        ^^        ^^        ^^        ^^\n";
            std::cout << "  ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^\n";
            std::cout << " ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^\n";
            std::cout << "^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^\033[0m\n";
            std::cout << "\033[2;33m   ||        ||        ||        ||        ||        ||        ||        ||        ||        ||        ||        ||        ||\n";
            std::cout << "   ||        ||        ||        ||        ||        ||        ||        ||        ||        ||        ||        ||        ||        \033[0m\n\n";

            if (anim == 0 || anim == 4)
            { // Neutral
                std::cout << m << "        .▄▄█▀▀▀█▄▄.       \n";
                std::cout << m << "       ▄█▀  ▄▄▄  ▀█▄      \n";
                std::cout << m << "       █   █▀█▀█   █      \n";
                std::cout << m << "       ▀█▄  ▀▀▀  ▄█▀      \n";
                std::cout << m << "      .▄▄█▓▓▓▓▓▓▓█▄▄.     \n";
                std::cout << m << "     ████▓▓▓▓█▓▓▓▓████    \n";
                std::cout << m << "    ████ ▓▓▓▓█▓▓▓▓ ████   \n";
                std::cout << m << "     ▀▀  █▓▓▓█▓▓▓█  ▀▀    \n";
                std::cout << m << "         █████████        \n";
                std::cout << m << "         ███   ███        \n";
                std::cout << m << "        ▄███   ███▄       \n";
            }
            else if (anim == 1 || anim == 2)
            { // Derecha adelante
                std::cout << m << "         .▄▄█▀▀▀█▄▄.      \n";
                std::cout << m << "        ▄█▀  ▄▄▄  ▀█▄     \n";
                std::cout << m << "        █   █▀█▀█   █     \n";
                std::cout << m << "        ▀█▄  ▀▀▀  ▄█▀     \n";
                std::cout << m << "       .▄▄█▓▓▓▓▓▓▓█▄      \n";
                std::cout << m << "     ▄████▓▓▓▓█▓▓▓▓█      \n";
                std::cout << m << "    █████ ▓▓▓▓█▓▓▓▓█      \n";
                std::cout << m << "          █████████▀      \n";
                std::cout << m << "          ███  ▀███▄      \n";
                std::cout << m << "          ███    ▀███▄    \n";
                std::cout << m << "         ▄███▄       ▀▀   \n";
            }
            else if (anim == 3)
            { // Zancada derecha
                std::cout << m << "          .▄▄█▀▀▀█▄▄.     \n";
                std::cout << m << "         ▄█▀  ▄▄▄  ▀█▄    \n";
                std::cout << m << "         █   █▀█▀█   █    \n";
                std::cout << m << "         ▀█▄  ▀▀▀  ▄█▀    \n";
                std::cout << m << "      .▄▄█▓▓▓▓▓▓▓█▄▄▄     \n";
                std::cout << m << "     ████▓▓▓▓█▓▓▓▓████▄   \n";
                std::cout << m << "         █▓▓▓█▓▓▓▓        \n";
                std::cout << m << "        ▄█████████▄       \n";
                std::cout << m << "       ███▀     ▀███      \n";
                std::cout << m << "      ███▀       ▀███     \n";
                std::cout << m << "    ▀▀▀             ▀▀▀   \n";
            }
            else if (anim == 5 || anim == 6)
            { // Izquierda adelante
                std::cout << m << "        .▄▄█▀▀▀█▄▄.       \n";
                std::cout << m << "       ▄█▀  ▄▄▄  ▀█▄      \n";
                std::cout << m << "       █   █▀█▀█   █      \n";
                std::cout << m << "       ▀█▄  ▀▀▀  ▄█▀      \n";
                std::cout << m << "        ▄█▓▓▓▓▓▓▓█▄▄.     \n";
                std::cout << m << "        █▓▓▓▓█▓▓▓▓████▄   \n";
                std::cout << m << "        █▓▓▓▓█▓▓▓▓ █████  \n";
                std::cout << m << "        ▀█████████        \n";
                std::cout << m << "       ▄███▀  ███         \n";
                std::cout << m << "     ▄███▀    ███         \n";
                std::cout << m << "    ▀▀       ▄███▄        \n";
            }
            else if (anim == 7)
            { // Zancada izquierda
                std::cout << m << "        .▄▄█▀▀▀█▄▄.       \n";
                std::cout << m << "       ▄█▀  ▄▄▄  ▀█▄      \n";
                std::cout << m << "       █   █▀█▀█   █      \n";
                std::cout << m << "       ▀█▄  ▀▀▀  ▄█▀      \n";
                std::cout << m << "      ▄▄▄█▓▓▓▓▓▓▓█▄▄.     \n";
                std::cout << m << "    ▄████▓▓▓▓█▓▓▓▓████    \n";
                std::cout << m << "         █▓▓▓█▓▓▓▓        \n";
                std::cout << m << "       ▄█████████▄        \n";
                std::cout << m << "      ███▀     ▀███       \n";
                std::cout << m << "     ███▀       ▀███      \n";
                std::cout << m << "   ▀▀▀             ▀▀▀    \n";
            }

            std::cout << "\n\n\033[32m   ^^        ^^        ^^        ^^        ^^        ^^        ^^        ^^        ^^        ^^        ^^        ^^        ^^\n";
            std::cout << "  ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^\n";
            std::cout << " ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^\n";
            std::cout << "^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^\033[0m\n";
            std::cout << "\033[2;33m   ||        ||        ||        ||        ||        ||        ||        ||        ||        ||        ||        ||        ||\n";
            std::cout << "   ||        ||        ||        ||        ||        ||        ||        ||        ||        ||        ||        ||        ||        \033[0m\n\n";

            std::this_thread::sleep_for(std::chrono::milliseconds(60));
        }
    }
    void showTreasureFound()
    {
        for (int i = 0; i < 10; ++i)
        {
            clear();
            int frame = i % 2;

            std::cout << "\n\n\n";
            std::cout << "                                                       ¡¡¡ 𝙑 𝙄 𝘾 𝙏 𝙊 𝙍 𝙄 𝘼 !!! - 𝙍 𝙀 𝙇 𝙄 𝙌 𝙐 𝙄 𝘼  𝙀 𝙉 𝘾 𝙊 𝙉 𝙏 𝙍 𝘼 𝘿 𝘼 \n\n";

            if (frame == 0)
            {

                std::cout << "\033[1;33m";
                std::cout << tabs << "                                              .▄▄█▀▀▀█▄▄.       \n";
                std::cout << tabs << "                                             ▄█▀  ▄▄▄  ▀█▄      \n";
                std::cout << tabs << "                                             █   █▀█▀█   █      \n";
                std::cout << tabs << "                                             ▀█▄  ▀▀▀  ▄█▀      \n";
                std::cout << tabs << "                                          █▄▄▄█▓▓▓▓▓▓▓█▄▄▄█     \n";
                std::cout << tabs << "                                          ████▓▓▓▓█▓▓▓▓████     \n";
                std::cout << tabs << "                                          ████ ▓▓▓▓█▓▓▓▓ ████   \n";
                std::cout << tabs << "                                               █████████        \n";
                std::cout << tabs << "                                              ▄███   ███▄       \n";
                std::cout << "\033[0m";
            }
            else
            {
                std::cout << "\033[1;35m";
                std::cout << tabs << "                                              .▄▄█▀▀▀█▄▄.       \n";
                std::cout << tabs << "                                             ▄█▀  ▄▄▄  ▀█▄      \n";
                std::cout << tabs << "                                             █   █▀█▀█   █      \n";
                std::cout << tabs << "                                             ▀█▄  ▀▀▀  ▄█▀      \n";
                std::cout << tabs << "                                          █▀▀▀█▓▓▓▓▓▓▓█▀▀▀█     \n";
                std::cout << tabs << "                                          ████▓▓▓▓█▓▓▓▓████     \n";
                std::cout << tabs << "                                               █████████        \n";
                std::cout << tabs << "                                              ▄███▀ ▀███▄       \n";
                std::cout << tabs << "                                              ▀▀▀     ▀▀▀        \n";
                std::cout << "\n\n\033[0m";
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
    }
    void showTreasure_not_found()
    {
        std::string frames[] = {

            // FRAME 1
            "\n                                                                              .▄▄█▀▀▀█▄▄.       \n"
            "                                                                             ▄█▀  ▄▄▄  ▀█▄      \n"
            "                                                                             █   █-█-█   █      \n"
            "                                                                             ▀█▄  ▀▀▀  ▄█▀      \n"
            "                                                                            .▄▄█▓▓▓▓▓▓▓█▄▄.     \n"
            "                                                                               █████████        \n"
            "                                                                               ███   ███        \n",

            // FRAME 2
            "                                                                                                \n"
            "                                                                              .▄▄█▀▀▀█▄▄.       \n"
            "                                                                             ▄█▀  ▄▄▄  ▀█▄      \n"
            "                                                                             █   █x█x█   █      \n"
            "                                                                             ▄▄█▓▓▓▓▓▓▓█▄▄.     \n"
            "                                                                            ███▀▀▀███▀▀▀███     \n",

            // FRAME 3
            "                                                                                                 \n"
            "                                                                                                 \n"
            "                                                                                                 \n"
            "                                                                                .▄▄█▀▀▀█▄▄.      \n"
            "                                                                             ▄▄▄█▓▓▓▓▓▓▓█▄▄▄     \n"
            "                                                                            ████▀▀▀▀▀▀▀▀▀████    \n"};
        for (int i = 0; i < 6; ++i)
        {
            clear();
            int frame = i % 3;

            std::cout << "\n\n\n";
            std::cout << "\033[31m";
            std::cout << "                                                   ☠  D E R R O T A  ☠  -  T E  Q U E D A S T E  S I N  E N E R G I A\n\n";

            std::cout << "\033[91m";
            std::cout << tabs << frames[frame];

            std::cout << "\033[0m";

            std::this_thread::sleep_for(std::chrono::milliseconds(700));
        }
    }
    void showGo_rest_first(bool training)
    {
        std::string frames[] = {

            // FRAME 1
            "\n                                                                       .▄▄█▀▀▀█▄▄.       \n"
            "                                                                      ▄█▀  ▄▄▄  ▀█▄      \n"
            "                                                                      █   █-█-█   █      \n"
            "                                                                      ▀█▄  ▀▀▀  ▄█▀      \n"
            "                                                                     .▄▄█▓▓▓▓▓▓▓█▄▄.     \n"
            "                                                                        █████████        \n"
            "                                                                        ███   ███        \n",

            // FRAME 2
            "                                                                                         \n"
            "                                                                       .▄▄█▀▀▀█▄▄.       \n"
            "                                                                      ▄█▀  ▄▄▄  ▀█▄      \n"
            "                                                                      █   █x█x█   █      \n"
            "    .                                                                 ▄▄█▓▓▓▓▓▓▓█▄▄.     \n"
            "                                                                     ███▀▀▀███▀▀▀███     \n",

            // FRAME 3
            "                                                                                         \n"
            "                                                                                         \n"
            "                                                                                         \n"
            "                                                                        .▄▄█▀▀▀█▄▄.      \n"
            "                                                                     ▄▄▄█▓▓▓▓▓▓▓█▄▄▄     \n"
            "                                                                    ████▀▀▀▀▀▀▀▀▀████    \n"};
        for (int i = 0; i < 6; ++i)
        {
            clear();
            int frame = i % 3;

            std::cout << "\n\n\n";
            std::cout << "\033[31m";
            std::cout << "                                                     ☠  T E  Q U E D A S T E  S I N  E N E R G I A  ☠ \n";
            if (training == true)
            {
                std::cout << "                             V E   A   D E S C A N S A R   A N T E S   D E  C O M E N Z A R   E L   E N T R E N A M I E N T O\n\n";
            }
            else
            {
                std::cout << "                                   V E   A   D E S C A N S A R   A N T E S   D E  C O M E N Z A R   L A   M I S I Ó N\n\n";
            }

            std::cout << "\033[91m";
            std::cout << tabs << frames[frame];

            std::cout << "\033[0m";

            std::this_thread::sleep_for(std::chrono::milliseconds(700));
        }
    }
    void showGoodbye()
    {
        clear();
        std::cout << tabs << "         █████╗ ██╗   ██╗    ██████╗ ███████╗██╗   ██╗ ██████╗ ██╗██████╗                                    \n";
        std::cout << tabs << "        ██╔══██╗██║   ██║    ██╔══██╗██╔════╝██║   ██║██╔═══██╗██║██╔══██╗                                   \n";
        std::cout << tabs << "        ███████║██║   ██║    ██████╔╝█████╗  ██║   ██║██║   ██║██║██████╔╝                                   \n";
        std::cout << tabs << "        ██╔══██║██║   ██║    ██╔══██╗██╔══╝  ╚██╗ ██╔╝██║   ██║██║██╔══██╗                                   \n";
        std::cout << tabs << "        ██║  ██║╚██████╔╝    ██║  ██║███████╗ ╚████╔╝ ╚██████╔╝██║██║  ██║                                   \n";
        std::cout << tabs << "        ╚═╝  ╚═╝ ╚═════╝     ╚═╝  ╚═╝╚══════╝  ╚═══╝   ╚═════╝ ╚═╝╚═╝  ╚═╝                                   \n";
        std::cout << tabs << "                                                                                                             \n";
        std::cout << tabs << "                        ███╗   ███╗ ██████╗ ███╗   ██╗███████╗██╗███████╗██╗   ██╗██████╗                    \n";
        std::cout << tabs << "                        ████╗ ████║██╔═══██╗████╗  ██║██╔════╝██║██╔════╝██║   ██║██╔══██╗                   \n";
        std::cout << tabs << "                        ██╔████╔██║██║   ██║██╔██╗ ██║███████╗██║█████╗  ██║   ██║██████╔╝                   \n";
        std::cout << tabs << "                        ██║╚██╔╝██║██║   ██║██║╚██╗██║╚════██║██║██╔══╝  ██║   ██║██╔══██╗                   \n";
        std::cout << tabs << "                        ██║ ╚═╝ ██║╚██████╔╝██║ ╚████║███████║██║███████╗╚██████╔╝██║  ██║                   \n";
        std::cout << tabs << "                        ╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═╝╚══════╝ ╚═════╝ ╚═╝  ╚═╝                   \n";
    }
    void showRest()
    {
        for (int i = 0; i < 21; ++i)
        { // 21 para que complete 7 ciclos de las 3 fases
            clear();
            int frame = i % 3; // Determina cuál de las 3 escenas mostrar
            if (frame == 0)
            {
                std::cout << "\n\033[38;5;39m                                              █▀█ █▀▀ █▀▀ ▄▀█ █▀█ █▀▀ ▄▀█ █▄░█ █▀▄ █▀█ \n";
                std::cout << "                                              █▀▄ ██▄ █▄▄ █▀█ █▀▄ █▄█ █▀█ █░▀█ █▄▀ █▄█   E N E R G Í A   Y   V I D A   (1 0 0 %)\033[0m\n";
                std::cout << "\n\n"
                          << tabs << "\033[38;5;229m                       .oooooo.                                      \n";
                std::cout << tabs << "                     d8P'    `Y8b                                    \033[0m\n";
                std::cout << tabs << "\033[38;5;229m                     888                           \033[0m.▄▄█▀▀▀█▄▄.       \n";
                std::cout << tabs << "\033[38;5;229m                     888                   \033[0mz      ▄█▀  ▄▄▄  ▀█▄      \n";
                std::cout << tabs << "\033[38;5;229m                     888                     \033[0mZ    █   █-█-█   █      \n";
                std::cout << tabs << "\033[38;5;229m                     `88b    ooo                  \033[0m▀█▄  ▀▀▀  ▄█▀      \n";
                std::cout << tabs << "\033[38;5;229m                      `Y8bood8P'                                     \033[0m\n";
                std::cout << tabs << "                                                 ▄▄▄█▓▓▓▓▓▓▓█▄▄▄     \n";
                std::cout << tabs << "                                                ████▓▓▓▓█▓▓▓▓████    \n";
                std::cout << tabs << "                                                   ▓▓▓▓ █ ▓▓▓▓       \n";
                std::cout << tabs << "                                                \n";
                std::cout << tabs << "                                                \n";
                std::cout << tabs << "                                                \n";
            }
            else if (frame == 1)
            {
                std::cout << "\n\033[38;5;39m                                              █▀█ █▀▀ █▀▀ ▄▀█ █▀█ █▀▀ ▄▀█ █▄░█ █▀▄ █▀█ \n";
                std::cout << "                                              █▀▄ ██▄ █▄▄ █▀█ █▀▄ █▄█ █▀█ █░▀█ █▄▀ █▄█   E N E R G Í A   Y   V I D A   (1 0 0 %)\033[0m\n";
                std::cout << "\n\n"
                          << tabs << "\033[38;5;229m                       .oooooo.                                      \n";
                std::cout << tabs << "                     d8P'    `Y8b                \033[0mz                    \n";
                std::cout << tabs << "\033[38;5;229m                     888                      \033[0mZ    .▄▄█▀▀▀█▄▄.       \n";
                std::cout << tabs << "\033[38;5;229m                     888                   \033[0mZ      ▄█▀  ▄▄▄  ▀█▄      \n";
                std::cout << tabs << "\033[38;5;229m                     888                     \033[0mZ    █   █-█-█   █      \n";
                std::cout << tabs << "\033[38;5;229m                     `88b    ooo                  \033[0m▀█▄  ▀▀▀  ▄█▀      \n";
                std::cout << tabs << "\033[38;5;229m                      `Y8bood8P'                                     \033[0m\n";
                std::cout << tabs << "                                                 ▄▄▄█▓▓▓▓▓▓▓█▄▄▄     \n";
                std::cout << tabs << "                                                ████▓▓▓▓█▓▓▓▓████    \n";
                std::cout << tabs << "                                                   ▓▓▓▓ █ ▓▓▓▓       \n";
                std::cout << tabs << "                                                \n";
                std::cout << tabs << "                                                \n";
                std::cout << tabs << "                                                \n";
            }
            else
            { // frame == 2
                std::cout << "\n\033[38;5;39m                                              █▀█ █▀▀ █▀▀ ▄▀█ █▀█ █▀▀ ▄▀█ █▄░█ █▀▄ █▀█ \n";
                std::cout << "                                              █▀▄ ██▄ █▄▄ █▀█ █▀▄ █▄█ █▀█ █░▀█ █▄▀ █▄█   E N E R G Í A   Y   V I D A   (1 0 0 %)\033[0m\n";
                std::cout << "\n\n"
                          << tabs << "\033[38;5;229m                       .oooooo.                                      \n";
                std::cout << tabs << "                     d8P'    `Y8b                               \033[0mz      Z                  \n";
                std::cout << tabs << "\033[38;5;229m                     888                       \033[0mz   .▄▄█▀▀▀█▄▄.       \n";
                std::cout << tabs << "\033[38;5;229m                     888                \033[0mz    Z    ▄█▀  ▄▄▄  ▀█▄      \n";
                std::cout << tabs << "\033[38;5;229m                     888                       \033[0mZ  █   █-█-█   █      \n";
                std::cout << tabs << "\033[38;5;229m                     `88b    ooo                  \033[0m▀█▄  ▀▀▀  ▄█▀      \n";
                std::cout << tabs << "\033[38;5;229m                      `Y8bood8P'                                     \033[0m\n";
                std::cout << tabs << "                                                 ▄▄▄█▓▓▓▓▓▓▓█▄▄▄     \n";
                std::cout << tabs << "                                                ████▓▓▓▓█▓▓▓▓████    \n";
                std::cout << tabs << "                                                   ▓▓▓▓ █ ▓▓▓▓       \n";
                std::cout << tabs << "                                                                     \n";
                std::cout << tabs << "                                                                     \n";
                std::cout << tabs << "                                                                     \n";
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(700));
        }
    }
    void showMenu()
    { // rest | mission | train | stats | exit
        std::cout << "\033[38;5;39m";
        std::cout << tabs << "                            ███╗   ███╗███████╗███╗   ██╗██╗   ██╗\n";
        std::cout << tabs << "                            ████╗ ████║██╔════╝████╗  ██║██║   ██║\n";
        std::cout << tabs << "                            ██╔████╔██║█████╗  ██╔██╗ ██║██║   ██║\n";
        std::cout << tabs << "                            ██║╚██╔╝██║██╔══╝  ██║╚██╗██║██║   ██║\n";
        std::cout << tabs << "                            ██║ ╚═╝ ██║███████╗██║ ╚████║╚██████╔╝\n";
        std::cout << tabs << "                            ╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝ \n";
        std::cout << "\033[0m";
        std::cout << "\033[38;5;221m";
        std::cout << tabs << "                        a. Entrenar\n";
        std::cout << tabs << "                        b. Realizar Misión\n";
        std::cout << tabs << "                        c. Ver Estadísticas\n";
        std::cout << tabs << "                        d. Descansar\n";
        std::cout << tabs << "                        e. Salir\n";
        std::cout << "\033[0m";
        std::cout << tabs << "\033[38;5;141m                        >Elige tu opción: ";
    }
    void showStats(int health, int energy, int strength)
    { // getters of strength, energy & health
        clear();
        std::cout << tabs << "\033[38;5;39m ██████ ▄▄▄█████▓ ▄▄▄     ▓█████▄  ██▓  ██████ ▄▄▄█████▓ ██▓ ▄████▄    ██████   \033[0m\n";
        std::cout << tabs << "\033[38;5;39m▒██    ▒ ▓  ██▒ ▓▒▒████▄   ▒██▀ ██▌▓██▒▒██    ▒ ▓  ██▒ ▓▒▓██▒▒██▀ ▀█  ▒██    ▒  \033[0m\n";
        std::cout << tabs << "\033[38;5;39m░ ▓██▄   ▒ ▓██░ ▒░▒██  ▀█▄ ░██   █▌▒██▒░ ▓██▄   ▒ ▓██░ ▒░▒██▒▒▓█    ▄ ░ ▓██▄    \033[0m\n";
        std::cout << tabs << "\033[38;5;39m  ▒   ██▒░ ▓██▓ ░ ░██▄▄▄▄██░▓█▄   ▌░██░  ▒   ██▒░ ▓██▓ ░ ░██░▒▓▓▄ ▄██▒  ▒   ██▒ \033[0m\n";
        std::cout << tabs << "\033[38;5;39m▒██████▒▒  ▒██▒ ░  ▓█   ▓██▒░▒████▓ ░██░▒██████▒▒  ▒██▒ ░ ░██░▒ ▓███▀ ░▒██████▒▒\033[0m\n";
        std::cout << tabs << "\033[38;5;39m▒ ▒▓▒ ▒ ░  ▒ ░░    ▒▒   ▓▒█░ ▒▒▓  ▒ ░▓  ▒ ▒▓▒ ▒ ░  ▒ ░░   ░▓  ░ ░▒ ▒  ░▒ ▒▓▒ ▒ ░\033[0m\n";
        std::cout << tabs << "\033[38;5;39m░ ░▒  ░ ░    ░      ▒   ▒▒ ░ ░ ▒  ▒  ▒ ░░ ░▒  ░ ░    ░     ▒ ░  ░  ▒   ░ ░▒  ░ ░\033[0m\n";
        std::cout << tabs << "\033[38;5;39m░  ░  ░    ░        ░   ▒    ░ ░  ░  ▒ ░░  ░  ░    ░       ▒ ░░        ░  ░  ░  \033[0m\n";
        std::cout << tabs << "\033[38;5;39m      ░                  ░  ░   ░     ░        ░            ░  ░ ░            ░ \033[0m\n";
        std::cout << tabs << "\033[38;5;39m                               ░                               ░                \033[0m\n";

        std::cout << tabs << "\033[38;5;51m ＞ ＨＥＡＬＴＨ           " << "＞ ＥＮＥＲＧＹ           " << "＞ ＳＴＲＥＮＧＴＨ\033[0m  \n";
        std::cout << tabs << "  " << health << "/100                     " << energy << "/100                  " << strength << "/100\n";
        wait();
    }
};

class gladiator
{
private:
    int strength;
    int energy;
    int health;
    int randNumber;
    int secretNumber;
    bool reliquia_encontrada;

public:
    gladiator() : strength(10), energy(100), health(100), randNumber(0),
                  secretNumber(7), reliquia_encontrada(false) {}
    bool train()
    {
        if (energy == 0)
        {
            return false;
        }
        if (strength >= 100)
        {
            strength = 100;
            return true;
        }
        strength += 10;
        energy -= 10;
        return true;
    }
    bool mission()
    {
        if (energy == 0)
        {
            return false; // UI: "go rest first"
        }
        reliquia_encontrada = false; // reset before starting the mission
        while (energy > 0 && reliquia_encontrada == false)
        {
            walk();
            if (randNumber == secretNumber)
            {
                reliquia_encontrada = true;
            }
        }
        return reliquia_encontrada;
    }
    bool rest()
    {
        energy = 100;
        health = 100;
        return true; // then, UI can show the animation
    }
    void generateNum()
    {
        randNumber = rand() % 10;
    }
    void walk()
    {
        if (energy > 0)
        {
            energy -= 10;
        }
        generateNum();
    }
    // GETTERS
    int getstrength()
    {
        return strength;
    }
    int getEnergy()
    {
        return energy;
    }
    int getHealth()
    {
        return health;
    }
};

int main()
{
    srand(time(NULL)); // creamos la semilla para nros aleatorios
    validator validador;
    gladiator gladiador;
    UI ui;

    // health | energy | strength
    do
    {
        do
        {
            ui.clear();
            ui.showMenu();
            ui.setMenuOption();
        } while (validador.validateOption(ui.getMenuOption()) == false);

        switch ((ui.getMenuOption()).front())
        {
        case 'a':
            if (gladiador.train() == false)
            {
                ui.showGo_rest_first(true); // true == training, false == mission
                break;
            }
            else
            {
                ui.showTraining();
                break;
            }
        case 'b':
            if (gladiador.getEnergy() == 0)
            {
                ui.showGo_rest_first(false); // true == training, false == mission
                break;
            }
            ui.showMission();
            if (gladiador.mission() == true)
            {
                ui.showTreasureFound();
            }
            else
            {
                ui.showTreasure_not_found();
            }
            break;
        case 'c':
            ui.showStats(gladiador.getHealth(), gladiador.getEnergy(), gladiador.getstrength());
            break;
        case 'd':
            gladiador.rest();
            ui.showRest();
            break;
        case 'e':
            ui.showGoodbye();
            return 0;
        }
    } while ((ui.getMenuOption()).front() != 'e');

    return 0;
}