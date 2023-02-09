//This is the implementation file for the User Interface and contains all prompts and output messages for the user.

#include <iostream>
#include <string>
#include <regex>
#include "UserInterface.h"
using namespace std;

//**********************************************************************************************************************
// greetUser provides a greeting message to the user at the start of the program.
//**********************************************************************************************************************
void UserInterface::greetUser(){

    cout << "\n";
    cout << "                               WELCOME TO\n";
    cout << "_______       _____            __________                          _____ \n"
            "___    |___  ___  /______      ___  ____/___  _______________________  /_\n"
            "__  /| |  / / /  __/  __ \\     __  __/  __  |/_/__  __ \\  _ \\_  ___/  __/\n"
            "_  ___ / /_/ // /_ / /_/ /     _  /___  __>  < __  /_/ /  __/  /   / /_  \n"
            "/_/  |_\\__,_/ \\__/ \\____/      /_____/  /_/|_| _  .___/\\___//_/    \\__/  \n"
            "                                               /_/                       \n\n\n";

}

//**********************************************************************************************************************
// promptUser asks user if they would like to run a diagnostic, get repair recommendations, or exit
//**********************************************************************************************************************
string UserInterface::promptUser(bool diag, bool repair){
    regex re_name(R"(^\w+([A-Z]))",  regex_constants::ECMAScript);
    regex re_value(R"(\w+([A-Z])$)", regex_constants::ECMAScript);
    bool isValid = false;
    string raw;
    if(atStart){
        do {
            cout << "PLEASE SELECT MODE TO RUN (DIAGNOSTIC, REPAIR or EXIT): " << endl;
            cin >> raw;

            if(raw == "DIAGNOSTIC" || raw == "Diagnostic" || raw == "diagnostic" || raw == "D" || raw == "d"){
                raw = "DIAGNOSTIC";
                cout << "YOU HAVE SELECTED THE FOLLOWING MODE: " << raw << endl;
                isDiagnostic = true;
                isRepair = false;
                isValid = true;
            }
            else if(raw == "REPAIR" || raw == "Repair" || raw == "repair" || raw =="R" || raw =="r"){
                raw = "REPAIR";
                cout << "YOU HAVE SELECTED THE FOLLOWING MODE: " << raw << endl;
                isDiagnostic = false;
                isRepair = true;
                isValid = true;
            }
            else if(raw == "EXIT" || raw == "Exit" || raw == "exit" || raw == "E" || raw == "e" ){
                raw = "EXIT";
                cout << "EXITING PROGRAM... " << endl;
                isDiagnostic = false;
                isRepair = false;
                isValid = true;
            }
            else {
                cout << "INVALID INPUT FOR MODE." << endl;
                isValid = false;
            }
        }while(!isValid);
        atStart = false;    // Mode for UI has been chosen, turn 'atStart' flag to access other prompts.
        return raw;
    }
    else{
        // If called from Diagnostic Engine...
        if(diag & !repair) {
            do {
                cout << "DOES THE CAR START? "
                        /*"(ISSUE_START or ISSUE_NO_START): "*/ "(YES or NO)" << endl;
                cin >> raw;
                transform(raw.begin(), raw.end(), raw.begin(), ::toupper);
                if (raw == "YES" || raw == "Y") {
                    raw = "ISSUE_START";
                    isValid = true;
                }
                else if (raw == "NO" || raw == "N") {
                    raw = "ISSUE_NO_START";
                    isValid = true;
                }
                else {
                    cout << "INVALID INPUT FOR ISSUE." << endl;
                    isValid = false;
                }
            } while (!isValid);
        }
        // If called from Repair Engine....
        else if(!diag & repair){
                // Implement this when diag portion is done.
            do {
                cout << "ENTER DIAGNOSTIC RESULT: " << endl;
                cin >> raw;
                transform(raw.begin(), raw.end(), raw.begin(), ::toupper);

                if(regex_match(raw, re_name)){
                    isValid = true;
                    }
                else {
                    cout << "INVALID INPUT FOR ISSUE." << endl;
                    isValid = false;
                }
            } while (!isValid);
            }
        // There is a problem if both diag and repair are set to true or set to false while atStart == false.
        else{
            cout << "SYSTEM ERROR ENCOUNTERED! EXITING PROGRAM..." << endl;
            raw = "EXIT";
        }
    }
    return raw;
}

//**********************************************************************************************************************
// getUserInput asks user for variable values, depending on whether they are running a diagnostic or need repair
// suggestions.
//**********************************************************************************************************************
string UserInterface::getUserInput( int i){
    string rawInput;
    bool isValid = false;
    if(!atStart){
    ////*************************************** DIAGNOSTIC PROMPTS ************************************************////
        if(isDiagnostic & !isRepair){
            switch (i)
            {
                case 0:
                    do {
                        cout << "DOES THE ENGINE ATTEMPT TO START WHEN YOU TURN THE IGNITION? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 1:
                    do {
                        cout << "DOES THE VEHICLE USE A FUEL INJECTION SYSTEM? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 2:
                    do {
                        cout << "DO THE INJECTORS APPEAR CLOGGED? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 3:
                    do {
                        cout << "IS ELECTRIC POWER AVAILABLE? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 4:
                    do {
                        cout << "IS THERE A CLICKING SOUND? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 5:
                    do {
                        cout << "IS THERE FLOODING IN CARBURETOR? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 6:
                    do {
                        cout << "DOES THE PROBLEM OCCUR SOMEWHERE ON THE VEHICLE's EXTERIOR? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 7:
                    do {
                        cout << "HAS ENGINE PERFORMANCE BEEN REDUCED? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 8:
                    do {
                        cout << "DOES THE VEHICLE HAVE DIFFICULTY SHIFTING GEARS? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 9:
                    do {
                        cout << "DOES THE ISSUE OCCUR WHEN THE VEHICLE IS IDLE? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 10:
                    do {
                        cout << "IS A SQUEALING NOISE PRESENT? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 11:
                    do {
                        cout << "DOES THE ENGINE OVERHEAT? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 12:
                    do {
                        cout << "DOES THE AC RUN BUT BLOW WARMER AIR THAN EXPECTED? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 13:
                    do {
                        cout << "DOES THE CAR HAVE AN AUTOMATIC TRANSMISSION? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 14:
                    do {
                        cout << "IS THE TRANSMISSION FLUID DISCOLORED? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 15:
                    do {
                        cout << "IS A BURNING SMELL PRESENT WHILE DRIVING? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 16:
                    do {
                        cout << "DOES THE CLUTCH PEDAL VIBRATE? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 17:
                    do {
                        cout << "IS THERE A DELAY WHEN SHIFTING GEARS? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 18:
                    do {
                        cout << "WHAT IS THE RESULT OF A COIL SWAP TEST ON SPARK PLUGS? (PASS or FAIL)";
                        cin >> rawInput;
                        if (rawInput == "PASS" || rawInput == "pass" || rawInput == "Pass" || rawInput == "P" ||
                            rawInput == "p") {
                            rawInput = "PASS";
                            isValid = true;

                        } else if (rawInput == "FAIL" || rawInput == "fail" || rawInput == "Fail" || rawInput == "F" ||
                                   rawInput == "f") {
                            rawInput = "FAIL";
                            isValid = true;

                        } else {
                            cout << "INPUT NOT VALID.\n";
                            exit(0);
                        }
                    }while(!isValid);
                    break;

                case 19:
                    do {
                        cout << "WHAT IS THE RESULT OF A SPARK PLUG SWAP TEST ON COILS? (PASS or FAIL)";
                        cin >> rawInput;
                        if (rawInput == "PASS" || rawInput == "pass" || rawInput == "Pass" || rawInput == "P" ||
                            rawInput == "p") {
                            rawInput = "PASS";
                            isValid = true;

                        } else if (rawInput == "FAIL" || rawInput == "fail" || rawInput == "Fail" || rawInput == "F" ||
                                   rawInput == "f") {
                            rawInput = "FAIL";
                            isValid = true;

                        } else {
                            cout << "INPUT NOT VALID.\n";
                            exit(0);
                        }
                    }while(!isValid);
                    break;
                case 20:
                    do {
                        cout << "IS THERE CORROSION ON THE DISTRIBUTOR CAP? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 21:
                    do {
                        cout << "DO INDICATORS SHOW LOW COOLANT LEVEL? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 22:
                    do {
                        cout << "IS THERE A COOLANT LEAK? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 23:
                    do {
                        cout << "IS THERE SLUDGE IN RADIATOR? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 24:
                    do {
                        cout << "DOES THE RADIATOR FAN RUN? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 25:
                    do {
                        cout << "IS THE WATER PUMP PULLEY LOOSE? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 26:
                    do {
                        cout << "DOES WHITE SMOKE COME FROM THE ENGINE? (YES or NO) ";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 27:
                    do {
                        cout << "ARE LEVELS FOR YOUR ENGINE OIL LOW? (YES or NO) ";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 28:
                    do {
                        cout << "DOES THE CAR SHAKE WHILE DRIVING? (YES or NO) ";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 29:
                    do {
                        cout << "HAS THE CAR HAD AN ALIGNMENT ADJUSTMENT DONE ON IT RECENTLY? (YES or NO) ";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 30:
                    do {
                        cout << "ARE THE LUG NUTS LOOSE, DAMAGED, or MISSING? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                case 31:
                    do {
                        cout << "DO SOME OF THE TIRES HAVE HIGHER OR LOWER PRESSURE THAN OTHERS? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    }while(!isValid);
                    break;

                default:
                    cout << "ERROR OCCURRED DURING VARIABLE INSTANTIATION. EXITING PROGRAM" << endl;
                    exit(0);
            }
            /* end of inputs statements for sample position knowledge
            base */

    ////*********************************** REPAIR ADVISOR PROMPTS ************************************************////
        }
        else if(!isDiagnostic & isRepair){
            // Implement once forward chaining program complete
            switch (i) {
                case 4:
                    do {
                        cout << "HAVE THE BATTERY TERMINALS BEEN CLEANED RECENTLY? (YES or NO)"; // Should never be asked as final is auto-initialized
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    } while (!isValid);
                    break;

                case 7:
                    do {
                        cout << "AFTER CLEANING THE TERMINALS, DOES THE BATTERY HOLD A CHARGE? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    } while (!isValid);
                    break;

                case 10:
                    do {
                        cout << "HAS THE AC SYSTEM BEEN CHECKED FOR LEAKS AND WERE ANY FOUND LEAKS REPAIRED? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    } while (!isValid);
                    break;

                case 21:
                    do {
                        cout << "DOES THE ENGINE BELT APPEAR FRAYED AND WORN? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    } while (!isValid);
                    break;

                case 23:
                    do {
                        cout << "HAS THE COOLANT HOSE BEEN REPLACED YET? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    } while (!isValid);
                    break;

                case 29:
                    do {
                        cout << "HAVE THE ENGINE SEALS AND GASKETS BEEN REPLACED YET? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    } while (!isValid);
                    break;

                case 32:
                    do {
                        cout << "DOES THE VEHICLE HAVE OVER 100K MILES ON IT? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    } while (!isValid);
                    break;

                case 33:
                    do {
                        cout << "IS THE VEHICLE OVER 5 YEARS OLD? (YES or NO)";
                        cin >> rawInput;
                        checkInput(isValid, rawInput);
                    } while (!isValid);
                    break;

                default:
                    cout << "ERROR OCCURRED DURING VARIABLE INSTANTIATION. EXITING PROGRAM" << endl;
                    exit(0);
            }
        }
        else{
            cout << "SYSTEM ERROR OCCURED. EXITING PROGRAM..." << endl;
            exit(0);
        }
    }
    return rawInput;
}

//**********************************************************************************************************************
// checkInput checks the user's input for variable instantiation - only applies to YES/NO answers.
//**********************************************************************************************************************
void UserInterface::checkInput(bool &isValid, string &rawInput){
    if (rawInput == "YES" || rawInput == "yes" || rawInput == "Yes" || rawInput == "Y" ||
        rawInput == "y") {
        rawInput = "YES";
        isValid = true;
    }
    else if (rawInput == "NO" || rawInput == "no" || rawInput == "No" || rawInput == "N" ||
             rawInput == "n") {
        rawInput = "NO";
        isValid = true;
    }
    else {
        cout << "INPUT NOT VALID.\n";
        isValid = false;
    }
}

//**********************************************************************************************************************
// showResults asks user if they would like to run a diagnostic, get repair recommendations, or exit
//**********************************************************************************************************************
void UserInterface::showResults(string result){
    if(isDiagnostic & !isRepair)
        cout << "YOUR DIAGNOSTIC RESULTS: " << result << endl;
    else if(!isDiagnostic & isRepair)
        cout << "SUGGESTED REPAIR ACTIONS: "<< result << endl;
}

//**********************************************************************************************************************
// changeMode switches the UI mode from DIAGNOSTIC to REPAIR or REPAIR to DIAGNOSTIC
//**********************************************************************************************************************
void UserInterface::changeMode(string mode){
    if(mode == "REPAIR"){
        isDiagnostic = false;
        isRepair = true;
    }
    else if(mode == "DIAGNOSTIC"){
        isDiagnostic = true;
        isRepair = false;
    }

}

