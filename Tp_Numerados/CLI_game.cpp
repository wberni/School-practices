#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

class UI {
    private:
        void clearCLI() {
            std::cout << "\033[H\033[J";
        }
        const std::string tabs;
    public:
        UI(): tabs("                                  ") {}
        void showTraining() {
            for (int i = 0; i < 20; ++i) {
                clearCLI(); 
                int rep = i / 2 + 1;
                std::cout << "\033[38;5;159m";
                if (i % 2 == 0) {
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
                } else {
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
                std::cout << tabs << "                         █▀█ █▀▀ █▀█ █▀▀ ▀█▀ █ █▀▀ █ █▀█ █▄░█ █▀▀ █▀ \n";
                std::cout << tabs << "                         █▀▄ ██▄ █▀▀ ██▄ ░█░ █ █▄▄ █ █▄█ █░▀█ ██▄ ▄█ " << rep << "\n";
                std::cout << "\033[0m";
                std::this_thread::sleep_for(std::chrono::milliseconds(380));
            }
        }
        void showMission() {
            const int totalFrames = 100;
            for (int i = 0; i < totalFrames; ++i)
            {
                    clearCLI();
                    std::string m(i / 2, ' '); // Avance físico
                    int anim = i % 8;

                    std::cout << "--- MISIÓN EN EL BOSQUE --- Distancia posible: " << i << "/100\n\n";

                    std::cout << "\033[32m   ^^        ^^        ^^        ^^        ^^        ^^        ^^        ^^        ^^\n";
                    std::cout << "  ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^\n";
                    std::cout << " ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^\n";
                    std::cout << "^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^\033[0m\n";
                    std::cout << "\033[2;33m   ||        ||        ||        ||        ||        ||        ||        ||        ||\n";
                    std::cout << "   ||        ||        ||        ||        ||        ||        ||        ||        ||\033[0m\n\n\n";

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
                
                    std::cout << "\n\n\033[32m   ^^        ^^        ^^        ^^        ^^        ^^        ^^        ^^        ^^\n";
                    std::cout << "  ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^      ^^^^\n";
                    std::cout << " ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^    ^^^^^^\n";
                    std::cout << "^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^^^^^\033[0m\n";
                    std::cout << "\033[2;33m   ||        ||        ||        ||        ||        ||        ||        ||        ||\n";
                    std::cout << "   ||        ||        ||        ||        ||        ||        ||        ||        ||\033[0m\n\n";
                
                    std::this_thread::sleep_for(std::chrono::milliseconds(60));
            }
        }
        void showTreasureFound() 
        {
            for (int i = 0; i < 10; ++i)
            {
                clearCLI();
                int frame = i % 2;

                std::cout << "\n\n\n";
                std::cout << "                              ¡¡¡ 𝙑 𝙄 𝘾 𝙏 𝙊 𝙍 𝙄 𝘼 !!! - 𝙍 𝙀 𝙇 𝙄 𝙌 𝙐 𝙄 𝘼  𝙀 𝙉 𝘾 𝙊 𝙉 𝙏 𝙍 𝘼 𝘿 𝘼 \n\n";

                if (frame == 0)
                {
                
                    std::cout << "\033[1;33m";
                    std::cout << tabs << "      .▄▄█▀▀▀█▄▄.       \n";
                    std::cout << tabs << "     ▄█▀  ▄▄▄  ▀█▄      \n";
                    std::cout << tabs << "     █   █▀█▀█   █      \n";
                    std::cout << tabs << "     ▀█▄  ▀▀▀  ▄█▀      \n";
                    std::cout << tabs << "  █▄▄▄█▓▓▓▓▓▓▓█▄▄▄█     \n";
                    std::cout << tabs << "  ████▓▓▓▓█▓▓▓▓████     \n";
                    std::cout << tabs << "  ████ ▓▓▓▓█▓▓▓▓ ████   \n";
                    std::cout << tabs << "       █████████        \n";
                    std::cout << tabs << "      ▄███   ███▄       \n";
                    std::cout << "\033[0m";
                }
                else
                {
                    std::cout << "\033[1;35m";
                    std::cout << tabs << "      .▄▄█▀▀▀█▄▄.       \n";
                    std::cout << tabs << "     ▄█▀  ▄▄▄  ▀█▄      \n";
                    std::cout << tabs << "     █   █▀█▀█   █      \n";
                    std::cout << tabs << "     ▀█▄  ▀▀▀  ▄█▀      \n";
                    std::cout << tabs << "  █▀▀▀█▓▓▓▓▓▓▓█▀▀▀█     \n";
                    std::cout << tabs << "  ████▓▓▓▓█▓▓▓▓████     \n";
                    std::cout << tabs << "       █████████        \n";
                    std::cout << tabs << "      ▄███▀ ▀███▄       \n";
                    std::cout << tabs << "     ▀▀▀     ▀▀▀        \n";
                    std::cout << "\n\n\033[0m";
                }
            
                std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
        }
        void showTreasure_not_found() {
            std::string frames[] = {

                // FRAME 1
                "\n                                                       .▄▄█▀▀▀█▄▄.       \n"
                "                                                      ▄█▀  ▄▄▄  ▀█▄      \n"
                "                                                      █   █-█-█   █      \n"
                "                                                      ▀█▄  ▀▀▀  ▄█▀      \n"
                "                                                     .▄▄█▓▓▓▓▓▓▓█▄▄.     \n"
                "                                                        █████████        \n"
                "                                                        ███   ███        \n",

                // FRAME 2
                "                                                                         \n"
                "                                                       .▄▄█▀▀▀█▄▄.       \n"
                "                                                      ▄█▀  ▄▄▄  ▀█▄      \n"
                "                                                      █   █x█x█   █      \n"
                "    .                                                 ▄▄█▓▓▓▓▓▓▓█▄▄.     \n"
                "                                                     ███▀▀▀███▀▀▀███     \n",

                // FRAME 3
                "                                                                         \n"
                "                                                                         \n"
                "                                                                         \n"
                "                                                        .▄▄█▀▀▀█▄▄.      \n"
                "                                                     ▄▄▄█▓▓▓▓▓▓▓█▄▄▄     \n"
                "                                                    ████▀▀▀▀▀▀▀▀▀████    \n"};
            for (int i = 0; i < 6; ++i)
            {
                clearCLI();
                int frame = i % 3;

                std::cout << "\n\n\n";
                std::cout << "\033[31m";
                std::cout << "                         ☠  D E R R O T A  ☠  -  T E  Q U E D A S T E  S I N  E N E R G I A\n\n";

                std::cout << "\033[91m";
                std::cout << tabs << frames[frame];

                std::cout << "\033[0m";

                std::this_thread::sleep_for(std::chrono::milliseconds(700));
            }
        }
        void showRest() {
            for (int i = 0; i < 21; ++i) { // 21 para que complete 7 ciclos de las 3 fases
                clearCLI(); 
                int frame = i % 3; // Determina cuál de las 3 escenas mostrar
                if (frame == 0) {
                    std::cout << "\n\n" << tabs << "\033[38;5;229m  .oooooo.                                      \n";         
                    std::cout << tabs << "d8P'    `Y8b                                    \033[0m\n";            
                    std::cout << tabs << "\033[38;5;229m888                           \033[0m.▄▄█▀▀▀█▄▄.       \n";             
                    std::cout << tabs << "\033[38;5;229m888                   \033[0mz      ▄█▀  ▄▄▄  ▀█▄      \n";                     
                    std::cout << tabs << "\033[38;5;229m888                     \033[0mZ    █   █-█-█   █      \n";                  
                    std::cout << tabs << "\033[38;5;229m`88b    ooo                  \033[0m▀█▄  ▀▀▀  ▄█▀      \n";                  
                    std::cout << tabs << "\033[38;5;229m `Y8bood8P'                                     \033[0m\n";                   
                    std::cout << tabs << "                            ▄▄▄█▓▓▓▓▓▓▓█▄▄▄     \n";                         
                    std::cout << tabs << "                           ████▓▓▓▓█▓▓▓▓████    \n";                        
                    std::cout << tabs << "                              ▓▓▓▓ █ ▓▓▓▓       \n";                         
                    std::cout << tabs << "                                                \n";                      
                    std::cout << tabs << "                                                \n";                           
                    std::cout << tabs << "                                                \n";
                } 
                else if (frame == 1) {
                    std::cout << "\n\n" << tabs << "\033[38;5;229m  .oooooo.                                      \n";         
                    std::cout << tabs << "d8P'    `Y8b                \033[0mz                    \n";            
                    std::cout << tabs << "\033[38;5;229m888                      \033[0mZ    .▄▄█▀▀▀█▄▄.       \n";             
                    std::cout << tabs << "\033[38;5;229m888                   \033[0mZ      ▄█▀  ▄▄▄  ▀█▄      \n";                     
                    std::cout << tabs << "\033[38;5;229m888                     \033[0mZ    █   █-█-█   █      \n";                  
                    std::cout << tabs << "\033[38;5;229m`88b    ooo                  \033[0m▀█▄  ▀▀▀  ▄█▀      \n";                  
                    std::cout << tabs << "\033[38;5;229m `Y8bood8P'                                     \033[0m\n";                   
                    std::cout << tabs << "                            ▄▄▄█▓▓▓▓▓▓▓█▄▄▄     \n";                         
                    std::cout << tabs << "                           ████▓▓▓▓█▓▓▓▓████    \n";                        
                    std::cout << tabs << "                              ▓▓▓▓ █ ▓▓▓▓       \n";                         
                    std::cout << tabs << "                                                \n";                      
                    std::cout << tabs << "                                                \n";                           
                    std::cout << tabs << "                                                \n";
                } 
                else { // frame == 2
                    std::cout << "\n\n" << tabs << "\033[38;5;229m  .oooooo.                                      \n";         
                    std::cout << tabs << "d8P'    `Y8b          \033[0mz      Z                  \n";            
                    std::cout << tabs << "\033[38;5;229m888                       \033[0mz   .▄▄█▀▀▀█▄▄.       \n";             
                    std::cout << tabs << "\033[38;5;229m888                \033[0mz    Z    ▄█▀  ▄▄▄  ▀█▄      \n";                     
                    std::cout << tabs << "\033[38;5;229m888                       \033[0mZ  █   █-█-█   █      \n";                  
                    std::cout << tabs << "\033[38;5;229m`88b    ooo                  \033[0m▀█▄  ▀▀▀  ▄█▀      \n";                  
                    std::cout << tabs << "\033[38;5;229m `Y8bood8P'                                     \033[0m\n";                   
                    std::cout << tabs << "                            ▄▄▄█▓▓▓▓▓▓▓█▄▄▄     \n";                         
                    std::cout << tabs << "                           ████▓▓▓▓█▓▓▓▓████    \n";                        
                    std::cout << tabs << "                              ▓▓▓▓ █ ▓▓▓▓       \n";                         
                    std::cout << tabs << "                                                \n";                      
                    std::cout << tabs << "                                                \n";                           
                    std::cout << tabs << "                                                \n";
                }

                std::this_thread::sleep_for(std::chrono::milliseconds(700));
            }
        }
        void showMenu(); //rest | mission | train | stats | exit
        void showStats(); //getters of strenght, energy & health
};



class gladiator {
    private:
        int strenght;
        int energy;
        int health;
        int randNumber;
        int secretNumber;
        bool reliquia_encontrada;
    public:
        gladiator() : strenght(10), energy(100), health(100), randNumber(0),
                        secretNumber(7), reliquia_encontrada(false) {}
        void train() {
            if (strenght >= 100) {
                strenght = 100;
                return;
            }
            strenght += 10;
        }
        bool mission() {
            if (energy == 0) {
                return false; // UI: "go rest first"
            }
            reliquia_encontrada = false; // reset before starting the mission
            while (energy > 0 && reliquia_encontrada == false) {
                walk();
                if (randNumber == secretNumber)
                {
                    reliquia_encontrada = true;
                }
            }
            return reliquia_encontrada;
        }
        bool rest() {
            energy = 100;
            health = 100;
            return true; // then, UI can show the animation
        }
        void walk() {
            if (energy > 0) {
                energy -= 10;
            }
            generateNum();
        }
        void generateNum() {
            randNumber = rand() % 10;
        }
        //GETTERS
        int getStrenght() {
            return strenght;
        }
        int getEnergy() {
            return energy;
        }
        int getHealth() {
            return health;
        }
};





int main()
{
    srand(time(NULL)); // creamos la semilla para nros aleatorios
    gladiator gladiador;
    UI ui;

    ui.showMission();
    if (gladiador.mission() == true)
    {
        ui.showTreasureFound();
    }
    else
    {
        ui.showTreasure_not_found();
    }

    return 0;
}