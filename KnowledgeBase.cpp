//
// Created by Rowan on 15.09.2019.
//
// Implementation file for the KnowledgeBase class.
#include "KnowledgeBase.h"  // Needed for the KnowledgeBase class
#include <iomanip>
#include<regex>             // Needed for use of Regular Expressions to parse strings
using namespace std;

//**********************************************************************************************************************
// initRepairRules initializes the repairRules vector for with the list of rules needed to run repair advisor (FC engine).
//**********************************************************************************************************************
void KnowledgeBase::initRepairRules(){

    // Declare rule variables
    rule rule1, rule2, rule3, rule4, rule5, rule6 , rule7, rule8, rule9, rule10, rule11, rule12, rule13, rule14, rule15,
            rule16, rule17, rule18, rule19, rule20, rule21, rule22, rule23, rule24, rule25, rule26, rule27, rule28, rule29,
            rule30, rule31, rule32, rule33, rule34, rule35, rule36, rule37, rule38, rule39, rule40, rule41;

    // NON-START ISSUE REPAIR RULES
    rule1.ruleNum = 10;
    rule1.clause[0] = "INJ_BAD_FUEL_PUMP = YES";
    rule1.clause[1] = "";
    rule1.clause[2] = "";
    rule1.clause[3] = "";
    rule1.conclusion = "REPLACE_FUEL_PUMP = YES";

    rule2.ruleNum = 20;
    rule2.clause[0] = "CARB_BAD_FUEL_PUMP = YES";
    rule2.clause[1] = "";
    rule2.clause[2] = "";
    rule2.clause[3] = "";
    rule2.conclusion = "REPLACE_FUEL_PUMP = YES";

    rule3.ruleNum = 30;
    rule3.clause[0] = "CLOGGED_INJECTORS = YES";
    rule3.clause[1] = "";
    rule3.clause[2] = "";
    rule3.clause[3] = "";
    rule3.conclusion = "CLEAN_INJECTORS = YES";

    rule4.ruleNum = 40;
    rule4.clause[0] = "DEAD_BATTERY = YES";
    rule4.clause[1] = "TERMINALS_CLEAN = NO";
    rule4.clause[2] = "";
    rule4.clause[3] = "";
    rule4.conclusion = "CLEAN_TERMINALS = YES";

    rule5.ruleNum = 50;
    rule5.clause[0] = "BAD_ALTERNATOR = YES";
    rule5.clause[1] = "";
    rule5.clause[2] = "";
    rule5.clause[3] = "";
    rule5.conclusion = "REPLACE_ALTERNATOR = YES";

    rule6.ruleNum = 60;
    rule6.clause[0] = "FLOODED_CARBURETOR = YES";
    rule6.clause[1] = "";
    rule6.clause[2] = "";
    rule6.clause[3] = "";
    rule6.conclusion = "EVAPORATE_EXCESS_FUEL = YES";

    rule7.ruleNum = 70;
    rule7.clause[0] = "DEAD_BATTERY = YES";
    rule7.clause[1] = "TERMINALS_CLEAN = YES";
    rule7.clause[2] = "CHARGE = NO";
    rule7.clause[3] = "";
    rule7.conclusion = "REPLACE_BATTERY = YES";

    rule8.ruleNum = 80;
    rule8.clause[0] = "DEAD_BATTERY = YES";
    rule8.clause[1] = "TERMINALS_CLEAN = YES";
    rule8.clause[2] = "CHARGE = YES";
    rule8.clause[3] = "";
    rule8.conclusion = "BAD_ALTERNATOR = YES";

    // REPAIR RULES FOR THE ISSUES WHERE THE CAR DOES START
    rule9.ruleNum=90;
    rule9.clause[0] = "LOW_FREON = YES";
    rule9.clause[1] = "";
    rule9.clause[2] = "";
    rule9.clause[3] = "";
    rule9.conclusion = "FREON_LEAK = YES";

    rule10.ruleNum=100;
    rule10.clause[0] = "FREON_LEAK = YES";
    rule10.clause[1] = "LEAK_REPAIRED = NO";
    rule10.clause[2] = "";
    rule10.clause[3] = "";
    rule10.conclusion = "REPAIR_AC_LEAK = YES";

    rule11.ruleNum=110;
    rule11.clause[0] = "FREON_LEAK = YES";
    rule11.clause[1] = "LEAK_REPAIRED = YES";
    rule11.clause[2] = "";
    rule11.clause[3] = "";
    rule11.conclusion = "PERFORM_AC_EVACUATION_RECHARGE = YES";

    rule12.ruleNum=120;
    rule12.clause[0] = "BAD_AC_COMPRESSOR = YES";
    rule12.clause[1] = "";
    rule12.clause[2] = "";
    rule12.clause[3] = "";
    rule12.conclusion = "REPLACE_COMPRESSOR = YES";

    rule13.ruleNum=130;
    rule13.clause[0] = "BAD_TRANSMISSION_FLUID = YES";
    rule13.clause[1] = "";
    rule13.clause[2] = "";
    rule13.clause[3] = "";
    rule13.conclusion = "REPLACE_TRANSMISSION_FLUID = YES";

    rule14.ruleNum=140;
    rule14.clause[0] = "BAD_CLUTCH_FLUID = YES";
    rule14.clause[1] = "";
    rule14.clause[2] = "";
    rule14.clause[3] = "";
    rule14.conclusion = "REPLACE_CLUTCH_FLUID = YES";

    rule15.ruleNum=150;
    rule15.clause[0] = "BAD_CLUTCH = YES";
    rule15.clause[1] = "";
    rule15.clause[2] = "";
    rule15.clause[3] = "";
    rule15.conclusion = "REPLACE_CLUTCH = YES";

    rule16.ruleNum=160;
    rule16.clause[0] = "BAD_FLYWHEEL = YES";
    rule16.clause[1] = "";
    rule16.clause[2] = "";
    rule16.clause[3] = "";
    rule16.conclusion = "REPLACE_FLYWHEEL = YES";

    rule17.ruleNum=170;
    rule17.clause[0] = "LOW_CLUTCH_FLUID = YES";
    rule17.clause[1] = "";
    rule17.clause[2] = "";
    rule17.clause[3] = "";
    rule17.conclusion = "ADD_CLUTCH_FLUID = YES";

    rule18.ruleNum=180;
    rule18.clause[0] = "BAD_SPARK_PLUG = YES";
    rule18.clause[1] = "";
    rule18.clause[2] = "";
    rule18.clause[3] = "";
    rule18.conclusion = "REPLACE_SPARK_PLUG = YES";

    rule19.ruleNum=190;
    rule19.clause[0] = "BAD_COIL = YES";
    rule19.clause[1] = "";
    rule19.clause[2] = "";
    rule19.clause[3] = "";
    rule19.conclusion = "REPLACE_COIL = YES";

    rule20.ruleNum=200;
    rule20.clause[0] = "DIST_CAP_DISCONNECT = YES";
    rule20.clause[1] = "";
    rule20.clause[2] = "";
    rule20.clause[3] = "";
    rule20.conclusion = "RECONNECT_DIST_CAP = YES";

    rule21.ruleNum=210;
    rule21.clause[0] = "DIRTY_WORN_BELT = YES";
    rule21.clause[1] = "WORN = YES";
    rule21.clause[2] = "";
    rule21.clause[3] = "";
    rule21.conclusion = "REPLACE_BELT = YES";

    rule22.ruleNum=220;
    rule22.clause[0] = "DIRTY_WORN_BELT = YES";
    rule22.clause[1] = "WORN = NO";
    rule22.clause[2] = "";
    rule22.clause[3] = "";
    rule22.conclusion = "APPLY_BELT_DRESSING = YES";

    rule23.ruleNum=230;
    rule23.clause[0] = "BAD_COOLANT_HOSE = YES";
    rule23.clause[1] = "HOSE_REPLACED = NO";
    rule23.clause[2] = "";
    rule23.clause[3] = "";
    rule23.conclusion = "REPLACE_HOSE = YES";

    rule24.ruleNum=240;
    rule24.clause[0] = "BAD_COOLANT_HOSE = YES";
    rule24.clause[1] = "HOSE_REPLACED = YES";
    rule24.clause[2] = "";
    rule24.clause[3] = "";
    rule24.conclusion = "LOW_COOLANT = YES";

    rule25.ruleNum=250;
    rule25.clause[0] = "LOW_COOLANT = YES";
    rule25.clause[1] = "";
    rule25.clause[2] = "";
    rule25.clause[3] = "";
    rule25.conclusion = "REFILL_COOLANT = YES";

    rule26.ruleNum=260;
    rule26.clause[0] = "BAD_FAN = YES";
    rule26.clause[1] = "";
    rule26.clause[2] = "";
    rule26.clause[3] = "";
    rule26.conclusion = "REPLACE_FAN = YES";

    rule27.ruleNum=270;
    rule27.clause[0] = "CRACKED_RADIATOR = YES";
    rule27.clause[1] = "";
    rule27.clause[2] = "";
    rule27.clause[3] = "";
    rule27.conclusion = "REPLACE_RADIATOR = YES";

    rule28.ruleNum=280;
    rule28.clause[0] = "BAD_WATER_PUMP = YES";
    rule28.clause[1] = "";
    rule28.clause[2] = "";
    rule28.clause[3] = "";
    rule28.conclusion = "REPLACE_WATER_PUMP = YES";

    rule29.ruleNum=290;
    rule29.clause[0] = "OIL_LEAK_ENG = YES";
    rule29.clause[1] = "REPLACE_GASKETS_SEALS = NO";
    rule29.clause[2] = "";
    rule29.clause[3] = "";
    rule29.conclusion = "REPLACE_GASKETS_SEALS = YES";

    rule30.ruleNum=300;
    rule30.clause[0] = "OIL_LEAK_OUT = YES";
    rule30.clause[1] = "";
    rule30.clause[2] = "";
    rule30.clause[3] = "";
    rule30.conclusion = "REPLACE_GASKETS_SEALS = YES";

    rule31.ruleNum=310;
    rule31.clause[0] = "OIL_LEAK_ENG = YES";
    rule31.clause[1] = "REPLACE_GASKETS_SEALS = YES";
    rule31.clause[2] = "";
    rule31.clause[3] = "";
    rule31.conclusion = "MAJOR_REPAIR = YES";

    rule32.ruleNum=320;
    rule32.clause[0] = "MAJOR_REPAIR = YES";
    rule32.clause[1] = "HIGH_MILEAGE = YES";
    rule32.clause[2] = "OVER_FIVE_YRS = YES";
    rule32.clause[3] = "";
    rule32.conclusion = "COST_EFFECTIVE = NO";

    rule33.ruleNum=330;
    rule33.clause[0] = "MAJOR_REPAIR = YES";
    rule33.clause[1] = "HIGH_MILEAGE = YES";
    rule33.clause[2] = "OVER_FIVE_YRS = NO";
    rule33.clause[3] = "";
    rule33.conclusion = "COST_EFFECTIVE = YES";

    rule34.ruleNum=340;
    rule34.clause[0] = "MAJOR_REPAIR = YES";
    rule34.clause[1] = "HIGH_MILEAGE = NO";
    rule34.clause[2] = "";
    rule34.clause[3] = "";
    rule34.conclusion = "COST_EFFECTIVE = YES";

    rule35.ruleNum=350;
    rule35.clause[0] = "BAD_ROTORS = YES";
    rule35.clause[1] = "";
    rule35.clause[2] = "";
    rule35.clause[3] = "";
    rule35.conclusion = "REPLACE_ROTORS = YES";

    rule36.ruleNum=360;
    rule36.clause[0] = "BAD_ALIGN = YES";
    rule36.clause[1] = "";
    rule36.clause[2] = "";
    rule36.clause[3] = "";
    rule36.conclusion = "PERFORM_WHEEL_ALIGNMENT = YES";

    rule37.ruleNum=370;
    rule37.clause[0] = "UNEVEN_TIRE_PRESS = YES";
    rule37.clause[1] = "";
    rule37.clause[2] = "";
    rule37.clause[3] = "";
    rule37.conclusion = "REINFLATE_TIRES_WITH_GAUGE = YES";

    rule38.ruleNum=380;
    rule38.clause[0] = "TIRES_UNBALANCED = YES";
    rule38.clause[1] = "";
    rule38.clause[2] = "";
    rule38.clause[3] = "";
    rule38.conclusion = "GET_TIRES_BALANCED = YES";

    rule39.ruleNum=390;
    rule39.clause[0] = "UNFASTENED_LUGS = YES";
    rule39.clause[1] = "";
    rule39.clause[2] = "";
    rule39.clause[3] = "";
    rule39.conclusion = "TIGHTEN_OR_REPLACE LUGNUTS = YES";

    rule40.ruleNum=400;
    rule40.clause[0] = "COST_EFFECTIVE = NO";
    rule40.clause[1] = "";
    rule40.clause[2] = "";
    rule40.clause[3] = "";
    rule40.conclusion = "REPLACE_VEHICLE = YES";

    rule41.ruleNum=410;
    rule41.clause[0] = "COST_EFFECTIVE = YES";
    rule41.clause[1] = "";
    rule41.clause[2] = "";
    rule41.clause[3] = "";
    rule41.conclusion = "REPLACE_CYLINDER_HEADS = YES";

    repairRules.push_back(rule1);
    repairRules.push_back(rule2);
    repairRules.push_back(rule3);
    repairRules.push_back(rule4);
    repairRules.push_back(rule5);
    repairRules.push_back(rule6);
    repairRules.push_back(rule7);
    repairRules.push_back(rule8);
    repairRules.push_back(rule9);
    repairRules.push_back(rule10);
    repairRules.push_back(rule11);
    repairRules.push_back(rule12);
    repairRules.push_back(rule13);
    repairRules.push_back(rule14);
    repairRules.push_back(rule15);
    repairRules.push_back(rule16);
    repairRules.push_back(rule17);
    repairRules.push_back(rule18);
    repairRules.push_back(rule19);
    repairRules.push_back(rule20);
    repairRules.push_back(rule21);
    repairRules.push_back(rule22);
    repairRules.push_back(rule23);
    repairRules.push_back(rule24);
    repairRules.push_back(rule25);
    repairRules.push_back(rule26);
    repairRules.push_back(rule27);
    repairRules.push_back(rule28);
    repairRules.push_back(rule29);
    repairRules.push_back(rule30);
    repairRules.push_back(rule31);
    repairRules.push_back(rule32);
    repairRules.push_back(rule33);
    repairRules.push_back(rule34);
    repairRules.push_back(rule35);
    repairRules.push_back(rule36);
    repairRules.push_back(rule37);
    repairRules.push_back(rule38);
    repairRules.push_back(rule39);
    repairRules.push_back(rule40);
    repairRules.push_back(rule41);

/*
            // TEST RULE SET
    rule1.ruleNum = 10;
    rule1.clause[0] = "FINAL = YES";
    rule1.clause[1] = "";
    rule1.clause[2] = "";
    rule1.clause[3] = "";
    rule1.conclusion = "GOAL = YES";

    rule2.ruleNum = 20;
    rule2.clause[0] = "TEST_A = YES";
    rule2.clause[1] = "TEST_B = NO";
    rule2.clause[2] = "";
    rule2.clause[3] = "";
    rule2.conclusion = "TEST_F = YES";

    rule3.ruleNum = 30;
    rule3.clause[0] = "TEST_A = YES";
    rule3.clause[1] = "TEST_B = YES";
    rule3.clause[2] = "";
    rule3.clause[3] = "";
    rule3.conclusion = "TEST_D = YES";

    rule4.ruleNum = 40;
    rule4.clause[0] = "TEST_F = YES";
    rule4.clause[1] = "TEST_C = YES";
    rule4.clause[2] = "";
    rule4.clause[3] = "";
    rule4.conclusion = "TEST_E = NO";

    rule5.ruleNum = 50;
    rule5.clause[0] = "TEST_D = YES";
    rule5.clause[1] = "TEST_E = YES";
    rule5.clause[2] = "";
    rule5.clause[3] = "";
    rule5.conclusion = "FINAL = YES";

    rule6.ruleNum = 60;
    rule6.clause[0] = "START = YES";
    rule6.clause[1] = "";
    rule6.clause[2] = "";
    rule6.clause[3] = "";
    rule6.conclusion = "TEST_A = YES";

    repairRules.push_back(rule1);
    repairRules.push_back(rule2);
    repairRules.push_back(rule3);
    repairRules.push_back(rule4);
    repairRules.push_back(rule5);
    repairRules.push_back(rule6);
*/
    // TESTING Print contents of repairRules vector
    //cout << "********* REPAIR RULES *********" << endl;
    //displayRuleBase(mode);
    //cout << "********************************" << endl;
}

//**********************************************************************************************************************
// initDiagRules initializes the diagRules vector for with the list of rules needed to run diagnostics (BC engine).
//**********************************************************************************************************************
void KnowledgeBase::initDiagRules(){

    // Declare rule variables
    rule rule1, rule2, rule3, rule4, rule5, rule6, rule7, rule8, rule9, rule10, rule11, rule12, rule13, rule14, rule15,
            rule16, rule17, rule18, rule19, rule20, rule21, rule22, rule23, rule24, rule25, rule26, rule27, rule28, rule29,
            rule30, rule31, rule32, rule33, rule34, rule35, rule36, rule37, rule38, rule39;

    // NON-STARTING RULES
    //NON-TERMINATING CONCLUSION RULES
    rule1.ruleNum = 10;
    rule1.clause[0] = "ATTEMPT = NO";
    rule1.clause[1] = "";
    rule1.clause[2] = "";
    rule1.clause[3] = "";
    rule1.conclusion = "ELECTRICAL = YES"; // Conclusion variable is also a clause variable for other rules.

    rule2.ruleNum = 20;
    rule2.clause[0] = "ATTEMPT = YES";
    rule2.clause[1] = "";
    rule2.clause[2] = "";
    rule2.clause[3] = "";
    rule2.conclusion = "FUEL = YES";    // Conclusion variable is also a clause variable for other rules.

    rule3.ruleNum = 30;
    rule3.clause[0] = "FUEL = YES";    // FUEL ISSUE
    rule3.clause[1] = "FUEL_INJ = NO";
    rule3.clause[2] = "";
    rule3.clause[3] = "";
    rule3.conclusion = "CARBURETED = YES";    // Conclusion variable is also a clause variable for other rules.

    // FINAL CONCLUSION RULES
    rule4.ruleNum = 40;
    rule4.clause[0] = "FUEL = YES";    // FUEL ISSUE
    rule4.clause[1] = "FUEL_INJ = YES";
    rule4.clause[2] = "INJ_CLOG = NO";
    rule4.clause[3] = "";
    rule4.conclusion = "ISSUE_NO_START = INJ_BAD_FUEL_PUMP";

    rule5.ruleNum = 50;
    rule5.clause[0] = "FUEL = YES"; // ADJUST
    rule5.clause[1] = "FUEL_INJ = YES";
    rule5.clause[2] = "INJ_CLOG = YES";
    rule5.clause[3] = "";
    rule5.conclusion = "ISSUE_NO_START = CLOGGED_INJECTORS";    // FINAL CONCLUSION

    rule6.ruleNum = 60;
    rule6.clause[0] = "ELECTRICAL = YES";
    rule6.clause[1] = "ELECTPOW = NO";
    rule6.clause[2] = "";
    rule6.clause[3] = "";
    rule6.conclusion = "ISSUE_NO_START = DEAD_BATTERY"; // FINAL CONCLUSION

    rule7.ruleNum = 70;
    rule7.clause[0] = "ELECTRICAL = YES";
    rule7.clause[1] = "ELECTPOW = YES";
    rule7.clause[2] = "CLICK = NO";
    rule7.clause[3] = "";
    rule7.conclusion = "ISSUE_NO_START = BAD_STARTER"; // FINAL CONCLUSION

    rule8.ruleNum = 80;
    rule8.clause[0] = "CARBURETED = YES";
    rule8.clause[1] = "CARB_FLOOD = YES";
    rule8.clause[2] = "";
    rule8.clause[3] = "";
    rule8.conclusion = "ISSUE_NO_START = FLOODED_CARBURETOR";    // FINAL CONCLUSION

    rule9.ruleNum = 90;
    rule9.clause[0] = "CARBURETED = YES";
    rule9.clause[1] = "CARB_FLOOD = NO";
    rule9.clause[2] = "";
    rule9.clause[3] = "";
    rule9.conclusion = "ISSUE_NO_START = CARB_BAD_FUEL_PUMP";    // FINAL CONCLUSION

    rule10.ruleNum = 100;
    rule10.clause[0] = "ELECTRICAL = YES";
    rule10.clause[1] = "ELECTPOW = YES";
    rule10.clause[2] = "CLICK = YES";
    rule10.clause[3] = "";
    rule10.conclusion = "ISSUE_NO_START = BAD_ALTERNATOR"; // FINAL CONCLUSION


    // STARTING RULES
    //NON-TERMINATING CONCLUSION RULES
    rule11.ruleNum = 110;
    rule11.clause[0] = "EXTERIOR = NO";
    rule11.clause[1] = "";
    rule11.clause[2] = "";
    rule11.clause[3] = "";
    rule11.conclusion = "AC_PROBLEM = YES";

    rule12.ruleNum = 120;
    rule12.clause[0] = "EXTERIOR = YES";
    rule12.clause[1] = "ENGINE = NO";
    rule12.clause[2] = "SHIFT = YES";
    rule12.clause[3] = "";
    rule12.conclusion = "TRANSMISSION = YES";

    rule13.ruleNum = 130;
    rule13.clause[0] = "EXTERIOR = YES";
    rule13.clause[1] = "ENGINE = YES";
    rule13.clause[2] = "SHIFT = NO";
    rule13.clause[3] = "";
    rule13.conclusion = "ENG_PROBLEM = YES";

    rule14.ruleNum = 140;
    rule14.clause[0] = "EXTERIOR = YES";
    rule14.clause[1] = "ENGINE = NO";
    rule14.clause[2] = "SHIFT = NO";
    rule14.clause[3] = "";
    rule14.conclusion = "WHEELS = YES";

    rule15.ruleNum = 150;
    rule15.clause[0] = "ENG_PROBLEM = YES";
    rule15.clause[1] = "IDLE = NO";
    rule15.clause[2] = "SQUEAL = NO";
    rule15.clause[3] = "OVERHEAT = YES";
    rule15.conclusion = "ENG_COOLING = YES"; // ENGINE COOLING PROBLEM

    rule16.ruleNum = 160;
    rule16.clause[0] = "ENG_PROBLEM = YES";
    rule16.clause[1] = "IDLE = NO";
    rule16.clause[2] = "SQUEAL = NO";
    rule16.clause[3] = "OVERHEAT = NO";
    rule16.conclusion = "ENG_OIL = YES"; // ENGINE OIL PROBLEM

    // FINAL CONCLUSION RULES
    rule17.ruleNum = 170;
    rule17.clause[0] = "AC_PROBLEM = YES";
    rule17.clause[1] = "AIRC_FUNCT = YES";
    rule17.clause[2] = "";
    rule17.clause[3] = "";
    rule17.conclusion = "ISSUE_START = LOW_FREON";

    rule18.ruleNum = 180;
    rule18.clause[0] = "AC_PROBLEM = YES";
    rule18.clause[1] = "AIRC_FUNCT = NO";
    rule18.clause[2] = "";
    rule18.clause[3] = "";
    rule18.conclusion = "ISSUE_START = BAD_AC_COMPRESSOR";

    rule19.ruleNum = 190;
    rule19.clause[0] = "TRANSMISSION = YES";
    rule19.clause[1] = "AUTO = YES";
    rule19.clause[2] = "";
    rule19.clause[3] = "";
    rule19.conclusion = "ISSUE_START = BAD_TRANSMISSION_FLUID";

    rule20.ruleNum = 200;
    rule20.clause[0] = "TRANSMISSION = YES";
    rule20.clause[1] = "AUTO = NO";     // If manual transmission
    rule20.clause[2] = "FLUID = YES";   // If transmission fluid is discolored
    rule20.clause[3] = "";
    rule20.conclusion = "ISSUE_START = BAD_CLUTCH_FLUID";

    rule21.ruleNum = 210;
    rule21.clause[0] = "TRANSMISSION = YES";
    rule21.clause[1] = "AUTO = NO";     // If manual transmission
    rule21.clause[2] = "BURN = YES";   // If there is a burning smell while driving
    rule21.clause[3] = "";
    rule21.conclusion = "ISSUE_START = BAD_CLUTCH";

    rule22.ruleNum = 220;
    rule22.clause[0] = "TRANSMISSION = YES";
    rule22.clause[1] = "AUTO = NO";     // If manual transmission
    rule22.clause[2] = "VIBE = YES";   // If there are clutch pedal vibrations
    rule22.clause[3] = "";
    rule22.conclusion = "ISSUE_START = BAD_FLYWHEEL";

    rule23.ruleNum = 230;
    rule23.clause[0] = "TRANSMISSION = YES";
    rule23.clause[1] = "AUTO = NO";     // If manual transmission
    rule23.clause[2] = "DELAY = YES"; // If there is a delay in gear shifting
    rule23.clause[3] = "";
    rule23.conclusion = "ISSUE_START = LOW_CLUTCH_FLUID";

    rule24.ruleNum = 240;
    rule24.clause[0] = "ENG_PROBLEM = YES";
    rule24.clause[1] = "IDLE = YES";
    rule24.clause[2] = "COIL_SWAP = FAIL";  // If spark plug does not work in different coil
    rule24.clause[3] = "SPARK_SWAP = PASS"; // If different spark plug doesn't work in coil
    rule24.conclusion = "ISSUE_START = BAD_SPARK_PLUG";

    rule25.ruleNum = 250;
    rule25.clause[0] = "ENG_PROBLEM = YES";
    rule25.clause[1] = "IDLE = YES";
    rule25.clause[2] = "COIL_SWAP = PASS";  // If spark plug works in a different coil
    rule25.clause[3] = "SPARK_SWAP = FAIL"; // If different spark plug doesn't work in coil
    rule25.conclusion = "ISSUE_START = BAD_COIL";

    rule26.ruleNum = 260;
    rule26.clause[0] = "ENG_PROBLEM = YES";
    rule26.clause[1] = "IDLE = YES";
    rule26.clause[2] = "CORROSION = YES";   // Corrosion on distributor cap
    rule26.clause[3] = "";
    rule26.conclusion = "ISSUE_START = DIST_CAP_DISCONNECT";

    rule27.ruleNum = 270;
    rule27.clause[0] = "ENG_PROBLEM = YES";
    rule27.clause[1] = "IDLE = NO";
    rule27.clause[2] = "SQUEAL = YES";
    rule27.clause[3] = "";
    rule27.conclusion = "ISSUE_START = DIRTY_WORN_BELT";

    rule28.ruleNum = 280;
    rule28.clause[0] = "ENG_COOLING = YES";
    rule28.clause[1] = "LOW_COOLANT = YES";
    rule28.clause[2] = "COOLANT_LEAK = YES";
    rule28.clause[3] = "SLUDGE = NO";
    rule28.conclusion = "ISSUE_START = BAD_COOLANT_HOSE";

    rule29.ruleNum = 290;
    rule29.clause[0] = "ENG_COOLING = YES";
    rule29.clause[1] = "LOW_COOLANT = YES";
    rule29.clause[2] = "COOLANT_LEAK = NO";
    rule29.clause[3] = "SLUDGE = NO";
    rule29.conclusion = "ISSUE_START = LOW_COOLANT";

    rule30.ruleNum = 300;
    rule30.clause[0] = "ENG_COOLING = YES";
    rule30.clause[1] = "LOW_COOLANT = NO";
    rule30.clause[2] = "COOLANT_LEAK = NO";
    rule30.clause[3] = "FANS_ON = NO";
    rule30.conclusion = "ISSUE_START = BAD_FAN";

    rule31.ruleNum = 310;
    rule31.clause[0] = "ENG_COOLING = YES";
    rule31.clause[1] = "LOW_COOLANT = YES";
    rule31.clause[2] = "COOLANT_LEAK = NO";
    rule31.clause[3] = "SLUDGE = YES";
    rule31.conclusion = "ISSUE_START = CRACKED_RADIATOR";

    rule32.ruleNum = 320;
    rule32.clause[0] = "ENG_COOLING = YES";
    rule32.clause[1] = "LOW_COOLANT = NO";
    rule32.clause[2] = "COOLANT_LEAK = YES";
    rule32.clause[3] = "PULLEY_LOOSE = YES";
    rule32.conclusion = "ISSUE_START = BAD_WATER_PUMP";

    rule33.ruleNum = 330;
    rule33.clause[0] = "ENG_OIL = YES";
    rule33.clause[1] = "WSMOKE = YES";
    rule33.clause[2] = "LOW_OIL = YES";
    rule33.clause[3] = "";
    rule33.conclusion = "ISSUE_START = OIL_LEAK_ENG";

    rule34.ruleNum = 340;
    rule34.clause[0] = "ENG_OIL = YES";
    rule34.clause[1] = "WSMOKE = NO";
    rule34.clause[2] = "LOW_OIL = YES";
    rule34.clause[3] = "";
    rule34.conclusion = "ISSUE_START = OIL_LEAK_OUT";

    rule35.ruleNum = 350;
    rule35.clause[0] = "WHEELS = YES";
    rule35.clause[1] = "SHAKE = NO";    // If the car shakes(or not) while driving
    rule35.clause[2] = "ALIGN = YES";   // If the car has had wheel alignment done recently
    rule35.clause[3] = "";
    rule35.conclusion = "ISSUE_START = BAD_ROTORS";

    rule36.ruleNum = 360;
    rule36.clause[0] = "WHEELS = YES";
    rule36.clause[1] = "SHAKE = NO";    // If the car shakes(or not) while driving
    rule36.clause[2] = "ALIGN = NO";
    rule36.clause[3] = "";
    rule36.conclusion = "ISSUE_START = BAD_ALIGN";

    rule37.ruleNum = 370;
    rule37.clause[0] = "WHEELS = YES";
    rule37.clause[1] = "SHAKE = YES";    // If the car shakes(or not) while driving
    rule37.clause[2] = "LUGS = NO";     // If lug nuts are missing or loose
    rule37.clause[3] = "PRESSURE = YES";    // If tire pressure is too low or too high in some tires
    rule37.conclusion = "ISSUE_START = UNEVEN_TIRE_PRESS";

    rule38.ruleNum = 380;
    rule38.clause[0] = "WHEELS = YES";
    rule38.clause[1] = "SHAKE = YES";    // If the car shakes(or not) while driving
    rule38.clause[2] = "LUGS = NO";     // If lug nuts are missing or loose
    rule38.clause[3] = "PRESSURE = NO";    // If uneven tire pressure
    rule38.conclusion = "ISSUE_START = TIRES_UNBALANCED";

    rule39.ruleNum = 390;
    rule39.clause[0] = "WHEELS = YES";
    rule39.clause[1] = "SHAKE = YES";    // If the car shakes(or not) while driving
    rule39.clause[2] = "LUGS = YES";     // If lug nuts are missing or loose
    rule39.clause[3] = "";    // If uneven tire pressure
    rule39.conclusion = "ISSUE_START = UNFASTENED_LUGS";

    diagRules.push_back(rule1);
    diagRules.push_back(rule2);
    diagRules.push_back(rule3);
    diagRules.push_back(rule4);
    diagRules.push_back(rule5);
    diagRules.push_back(rule6);
    diagRules.push_back(rule7);
    diagRules.push_back(rule8);
    diagRules.push_back(rule9);
    diagRules.push_back(rule10);
    diagRules.push_back(rule11);
    diagRules.push_back(rule12);
    diagRules.push_back(rule13);
    diagRules.push_back(rule14);
    diagRules.push_back(rule15);
    diagRules.push_back(rule16);
    diagRules.push_back(rule17);
    diagRules.push_back(rule18);
    diagRules.push_back(rule19);
    diagRules.push_back(rule20);
    diagRules.push_back(rule21);
    diagRules.push_back(rule22);
    diagRules.push_back(rule23);
    diagRules.push_back(rule24);
    diagRules.push_back(rule25);
    diagRules.push_back(rule26);
    diagRules.push_back(rule27);
    diagRules.push_back(rule28);
    diagRules.push_back(rule29);
    diagRules.push_back(rule30);
    diagRules.push_back(rule31);
    diagRules.push_back(rule32);
    diagRules.push_back(rule33);
    diagRules.push_back(rule34);
    diagRules.push_back(rule35);
    diagRules.push_back(rule36);
    diagRules.push_back(rule37);
    diagRules.push_back(rule38);
    diagRules.push_back(rule39);

    // TESTING Print contents of diagRules vector
    //cout << "******* DIAGNOSTIC RULES *******" << endl;
    //displayRuleBase("DIAGNOSTIC");
    //cout << "********************************" << endl;
}

//**********************************************************************************************************************
// initVarList initializes the varList vector with the list of variables to be used in the Variable List based on
// the entries in the ruleBase.
//**********************************************************************************************************************
void KnowledgeBase::initVarList(vector<rule> &ruleBase, vector<variable> &varList) {
    variable tempVar;     // temporary storage for variable

    try {
        regex re(R"(^\w+([A-Z]))", regex_constants::ECMAScript);   // Raw string literal to compare to variable names.
        // This raw string literal should capture ONLY characters A-Z on the left of the '=' in the clause.

        smatch match_results;   // Storage container for results that match the above raw string literal.
        // match_results[0] points to the start of the submatch and should give whole matching word
        // match_results[1] points to the end of the submatch and should give the last letter of match

        for (int i = 0; i < ruleBase.size(); i++) {
            if (ruleBase.at(i).ruleNum != 0) {

                // IF RULE HAS MORE THAN 3 CLAUSES
                for(int x = 0; x < CLAUSE_MAX; x++){
                    if (regex_search(ruleBase.at(i).clause[x], match_results, re)) {
                        // Tracing value of match_results[0]
                        //cout << "Regex match results: " << match_results[0] << "\n";
                        if (varList.empty()) {  // If there are no variables in the varList vector...
                            bool inConList = false; // Flag for conList check

                            // DIAGS ONLY
                            // Check Conclusion List to make sure variable isn't already in there
                            for (int j = 0; j < conList.size(); j++) {
                                if (match_results[0] == conList[j].label) { inConList = true; } // Set flag to true if conclusion.
                            }
                            // Push to variable list if it is not a conclusion variable
                            if (!inConList) {
                                pushVariable(varList, match_results, tempVar);
                            }
                        }
                            // If Variable List is not empty, check for duplicate in both variable and conclusion list
                        else if (!varList.empty()) {
                            checkDuplicatesVarList(varList, match_results, tempVar);
                        }
                    }
                }
            }
        }
        // Catch regex_error and display. If code = 2, it is due to outdated compiler
    }catch (const regex_error& e){
        cout << "regex_error caught: " << e.what() << " code: "<< e.code() << '\n';
        if (e.code() == regex_constants::error_brack){
            cout << "The code was error_brack\n";
        }
    }
    // TESTING
    //displayVarList(mode);
}

//**********************************************************************************************************************
// initConList initializes the conList vector with the list of conclusions based on the entries in the Diagnostic ruleBase.
// DIAGS ONLY
//**********************************************************************************************************************
void KnowledgeBase::initConList(vector<rule> &ruleBase){

    conVar temp;        // Temporary conVar variable
    string tempLabel;   // Temporary conVar label

    try {
        regex re_Name(R"(^\w+([A-Z]))", regex_constants::ECMAScript);   // Raw string literal to compare to
        // conclusion labels.
        // This raw string literal should capture ONLY characters A-Z on the left of the '=' in the conclusion.

        smatch match_results;   // Storage container for results that match the above raw string literal.
        // match_results[0] points to the start of the submatch and should give whole matching word
        // match_results[1] points to the end of the submatch and should give the last letter of match

        for (int i = 0; i < ruleBase.size(); i++) {
            if (ruleBase.at(i).ruleNum != 0) {
                if (regex_search(ruleBase.at(i).conclusion, match_results, re_Name)) {
                    // Tracing value of match_results[0]
                    //cout << "Regex match results: " << match_results[0] << "\n";
                    tempLabel = match_results[0];
                    temp.ruleNum = ruleBase[i].ruleNum;
                    temp.label = tempLabel;
                    temp.statement = ruleBase[i].conclusion;
                    conList.push_back(temp);
                }
            }
        }
    } catch (const regex_error& e){
        cout << "regex_error caught: " << e.what() << " code: " << e.code() << '\n';
    }
    // TESTING
    //displayConList();
}

//**********************************************************************************************************************
// initClauseVarList initializes the clauseVarList vector with the list of Clause Variables based on the entries in the
// ruleBase.
//**********************************************************************************************************************
void KnowledgeBase::initClauseVarList(vector<rule> &ruleBase, vector<clauseEntry> &clauseVarList) {
    // Iterate through Rule Base in order.
    int clauseVarNum;
    string clauseVarName;
    clauseEntry entry;

    smatch match_results;
    try {
        // Regex to capture label of variable
        regex re(R"(^\w+([A-Z]))", regex_constants::ECMAScript);

        for (int i = 0; i < ruleBase.size(); i++) {
            // Calculate position of clause variable in rule based on rule number using formula from BC notes.
            if (ruleBase[i].ruleNum != 0) {
                clauseVarNum = 5 * (ruleBase[i].ruleNum / 10 - 1) + 1;
                for (int j = 0; j < CLAUSE_MAX + 1; j++) {
                    entry.clauseNum = clauseVarNum + j;
                    switch (j) {
                        case 0:
                            regex_search(ruleBase.at(i).clause[0], match_results, re);
                            entry.clauseVar = match_results[0];
                            clauseVarList.push_back(entry);
                            break;
                        case 1:
                            // If a clause variable is an empty string, push empty string to clause variable vector anyway.
                            regex_search(ruleBase.at(i).clause[1], match_results, re);
                            entry.clauseVar = match_results[0];
                            clauseVarList.push_back(entry);
                            break;
                        case 2:
                            // If a clause variable is an empty string, push empty string to clause variable vector anyway.
                            regex_search(ruleBase.at(i).clause[2], match_results, re);
                            entry.clauseVar = match_results[0];
                            clauseVarList.push_back(entry);
                            break;
                        case 3:
                            // If a clause variable is an empty string, push empty string to clause variable vector anyway.
                            regex_search(ruleBase.at(i).clause[3], match_results, re);
                            entry.clauseVar = match_results[0];
                            clauseVarList.push_back(entry);
                            break;
                        case 4:
                            // Push an empty string following the 3rd clause to keep each set of clause variables/rule separate and index values
                            // consistent with formula.
                            entry.clauseVar = "";
                            clauseVarList.push_back(entry);
                            break;
                    }
                }
            }
        }

    }catch (const regex_error& e){
        cout << "regex_error caught: " << e.what() << " code: "<< e.code() << '\n';
    }
    // TESTING
    //displayClauseVarList();
}

//**********************************************************************************************************************
// initKB initializes the entire Knowledge Base with the previous functions.
//**********************************************************************************************************************
void KnowledgeBase::initKB() {

    initRepairRules();
    initDiagRules();
    initConList(diagRules);      // DIAGS ONLY
    initVarList(diagRules, diagVarList);
    initVarList(repairRules, repairVarList);
    initClauseVarList(diagRules, diagClauseVarList);
    initClauseVarList(repairRules, repairClauseVarList);
}
//**********************************************************************************************************************
// checkConList passes variable name to check if it is in the conclusion list. DIAGS ONLY
//**********************************************************************************************************************
int KnowledgeBase::checkConList(string &q) {
    //int i = 0;      // iterator variable
    int ruleNum = 0;
    // Routine to determine if the query variable is a member of the conclusion list.
    do{
        if(q == conList[startIndex].label){
            ruleNum = conList[startIndex].ruleNum;
            //cout << "ruleNum in checkConList() in IF of while loop = " << ruleNum << endl;
            //cout << "startIndex in checkConList() in IF of while loop = " << startIndex << endl;
            //return ruleNum;
        }
        else {
            startIndex = startIndex + 1;
            //cout << "startIndex in checkConList() in ELSE of while loop = " << startIndex << endl;
        }
        //cout << "In checkConList, conList.size() = " << conList.size() << " and startIndex is " << startIndex << endl;
    }while(startIndex < conList.size() && ruleNum == 0);
    //cout << "startIndex outside of while loop is " << startIndex << endl;
    //cout << "ruleNum in checkConList() outside of while loop = " << ruleNum << endl;
    return ruleNum;
}
//**********************************************************************************************************************
// setVariable takes an index value and the user's input for and sets the value for the corresponding variable in
// varList.
//**********************************************************************************************************************
void KnowledgeBase::setVariable(string &mode, string input, int index){
    if(mode == "DIAGNOSTIC")
        diagVarList[index].value = input;
    else if (mode == "REPAIR")
        repairVarList[index].value = input;
}

//**********************************************************************************************************************
// setVariable takes an index value and the user's input for and sets the value for the corresponding variable in
// varList.
//**********************************************************************************************************************
void KnowledgeBase::setStartIndex(int index){
    // Offset startIndex value for vector search.
    if(index - 1 >= 0)
        startIndex = index - 1;
    else
        startIndex = 0;
}
//**********************************************************************************************************************
// getStartIndex() returns the value of the StartIndex
//**********************************************************************************************************************
int KnowledgeBase::getStartIndex(){
    return startIndex;
}

//**********************************************************************************************************************
// getVariableName takes an index value and returns the variable Name at that location.
//**********************************************************************************************************************
string KnowledgeBase::getVariableName(string &mode, int index){
    string varName;
    if(mode == "DIAGNOSTIC")
        varName = diagVarList[index].name;
    else if(mode == "REPAIR")
        varName = repairVarList[index].name;
    return varName;
}
//**********************************************************************************************************************
// getVariableValue takes an index value and returns the variable value at that location.
//**********************************************************************************************************************
string KnowledgeBase::getVariableValue(string &mode, int index){
    string varVal;
    if(mode == "DIAGNOSTIC")
        varVal = diagVarList[index].value;
    else if(mode == "REPAIR")
        varVal = repairVarList[index].value;
    return varVal;
}

//**********************************************************************************************************************
// getVarListSize returns the size of the variable list
//**********************************************************************************************************************
int KnowledgeBase::getVarListSize(string &mode){
    int size;
    if(mode == "DIAGNOSTIC")
        size = diagVarList.size();
    else if(mode == "REPAIR")
        size = repairVarList.size();
    return size;
}

//**********************************************************************************************************************
// getClauseVariable takes input from the program for the name of a variable and returns it's value.
//**********************************************************************************************************************
string KnowledgeBase::getClauseVariable(string &mode, int index){
    string clauseVar;
    if(mode == "DIAGNOSTIC")
        clauseVar = diagClauseVarList[index].clauseVar;
    else if(mode == "REPAIR")
        clauseVar = repairClauseVarList[index].clauseVar;
    return clauseVar;
}

//**********************************************************************************************************************
// getConLabel takes an index value and returns the conclusion variable label at the index location in Conclusion List.
//**********************************************************************************************************************
string KnowledgeBase::getConLabel(int index){
    return conList[index].label;
}

//**********************************************************************************************************************
//getConcRuleNum receives an index value and returns the rule number associated with that conclusion from ConList
//**********************************************************************************************************************
int KnowledgeBase::getConcRuleNum(int index){
    return conList[index].ruleNum;
}
//**********************************************************************************************************************
// getRuleClause# receives an rule number, derives the correct index value and returns the first, second, or third
// clause string located in the ruleBase vector at the index location.
// ** Consider changing the rule struct to hold clauses in a string array later
//**********************************************************************************************************************
string KnowledgeBase::getRuleClause(string &mode, int ruleNum, int index){
    string ruleClause;
    if(mode == "DIAGNOSTIC") {
        ruleClause = diagRules[ruleNum / 10 - 1].clause[index];      // Divide rule number by 10 and subtract to get accurate index value
    }
    else if (mode == "REPAIR")
        ruleClause = repairRules[ruleNum/10-1].clause[index-1];
    return ruleClause;
}

//**********************************************************************************************************************
// getConclusion takes the rule number from stack, calculates corresponding index to appropriate conclusion statement in
// Conclusion List, then returns the value of the rule's conclusion.
//**********************************************************************************************************************
string KnowledgeBase::getConclusion(int ruleNum){
    int i = ruleNum/10; // Index starts at 0.
    return conList[i-1].statement;
}

//**********************************************************************************************************************
// getConListSize returns the size of the Conclusion List
//**********************************************************************************************************************
int KnowledgeBase::getConListSize(){
    return conList.size();
}

//**********************************************************************************************************************
// displayVarList displays the current contents of the Variable List for testing purposes.
//**********************************************************************************************************************
void KnowledgeBase::displayVarList(string mode) {

    cout << "**** VARIABLE LIST STATE ****\n";
    if(mode == "DIAGNOSTIC") {

        for (int i = 0; i < diagVarList.size(); i++) {
            cout << setw(20) << left << diagVarList[i].name << setw(5) << right << diagVarList[i].value << setw(5) << endl;
        }
    }
    else if(mode == "REPAIR") {

        for (int i = 0; i < repairVarList.size(); i++) {
            cout << setw(20) << left << repairVarList[i].name << setw(5) << right << repairVarList[i].value << setw(5) << endl;
        }
    }
    cout << "*****************************\n";
}

//**********************************************************************************************************************
// displayRuleBase displays Rule Base
//**********************************************************************************************************************
void KnowledgeBase::displayRuleBase(string mode){
    cout << "********  RULE BASE  ********\n";

    if(mode == "DIAGNOSTIC"){
    for (int i = 0; i < diagRules.size(); i++){
        if(diagRules.at(i).ruleNum != 0){
            if(diagRules.at(i).clause[1] == "" && diagRules.at(i).clause[2] == "") {
                cout << "Rule #" + to_string(diagRules.at(i).ruleNum) + ": IF " + diagRules.at(i).clause[0] +
                        " THEN " + diagRules.at(i).conclusion + "\n";
            }
            else if(diagRules.at(i).clause[1] != "" && diagRules.at(i).clause[2] == "") {
                cout << "Rule #" + to_string(diagRules.at(i).ruleNum) + ": IF " + diagRules.at(i).clause[0] + " AND "+
                        diagRules.at(i).clause[1] + " THEN " + diagRules.at(i).conclusion + "\n";
            }
            else if (diagRules.at(i).clause[1] != "" && diagRules.at(i).clause[2] != "") {
                cout << "Rule #" + to_string(diagRules.at(i).ruleNum) + ": IF " + diagRules.at(i).clause[0] + " AND "+
                        diagRules.at(i).clause[1] + " AND "+ diagRules.at(i).clause[2] +" THEN " +
                        diagRules.at(i).conclusion + "\n";
            }
        }
    }

}
    else if(mode == "REPAIR"){
        for (int i = 0; i < repairRules.size(); i++){
            if(repairRules.at(i).ruleNum != 0){
                if(repairRules.at(i).clause[1] == "" && repairRules.at(i).clause[2] == "") {
                    cout << "Rule #" + to_string(repairRules.at(i).ruleNum) + ": IF " + repairRules.at(i).clause[0] +
                            " THEN " + repairRules.at(i).conclusion + "\n";
                }
                else if(repairRules.at(i).clause[1] != "" && repairRules.at(i).clause[2] == "") {
                    cout << "Rule #" + to_string(repairRules.at(i).ruleNum) + ": IF " + repairRules.at(i).clause[0] + " AND "+
                            repairRules.at(i).clause[1] + " THEN " + repairRules.at(i).conclusion + "\n";
                }
                else if (repairRules.at(i).clause[1] != "" && repairRules.at(i).clause[2] != "") {
                    cout << "Rule #" + to_string(repairRules.at(i).ruleNum) + ": IF " + repairRules.at(i).clause[0] + " AND "+
                            repairRules.at(i).clause[1] + " AND "+ repairRules.at(i).clause[2] +" THEN " +
                            repairRules.at(i).conclusion + "\n";
                }
            }
        }

    }
    cout << "*****************************\n";
}

//**********************************************************************************************************************
// displayConList displays the Conclusion List (DIAGNOSTIC ONLY FUNCTION)
//**********************************************************************************************************************
void KnowledgeBase::displayConList() {
    cout << "*****  CONCLUSION LIST  *****\n";
    for (int i = 0; i < conList.size(); i++) {
        cout << "ConList Entry #" << i + 1 << ": Rule " << conList[i].ruleNum << " Label: " << conList[i].label
             << " - " << conList[i].statement << "\n";
    }
    cout << "*****************************\n";
}

//**********************************************************************************************************************
// displayClauseVarList displays the Clause Variable List
//**********************************************************************************************************************
void KnowledgeBase::displayClauseVarList(string mode){
    cout << "***** CLAUSE VARIABLE LIST *****\n";
    if(mode == "DIAGNOSTIC") {
        for (int i = 0; i < diagClauseVarList.size(); i++) {
            cout << setw(5) << right << diagClauseVarList[i].clauseNum << "\t" << left << diagClauseVarList[i].clauseVar <<
                 setw(5) << endl;
        }
    }
    else if(mode == "REPAIR"){
        for (int i = 0; i < repairClauseVarList.size(); i++) {
            cout << setw(5) << right << repairClauseVarList[i].clauseNum << "\t" << left << repairClauseVarList[i].clauseVar <<
                 setw(5) << endl;
        }
    }
    cout << "********************************\n";
}

//**********************************************************************************************************************
// getRuleClauseMax returns the maximum number of clauses a rule can have.
//**********************************************************************************************************************
const int  KnowledgeBase::getRuleClauseMax(){
    return CLAUSE_MAX;
}

//**********************************************************************************************************************
// checkDuplicatesVarList checks the variable list for duplicates before adding new variables to the list
//**********************************************************************************************************************
void KnowledgeBase::checkDuplicatesVarList(vector<variable> &varList, smatch &match_results, variable &tempVar){
    bool inConList = false; // Flag for conList check
    // Check Conclusion List to make sure variable isn't already in there
    for (int j = 0; j < conList.size(); j++) {
        if (match_results[0] == conList[j].label) { inConList = true; } // Set flag to true if conclusion.
    }
    // If not a conclusion variable, then check for duplicate in varList
    if (!inConList) {
        bool duplicate = false; // Flag for existing duplicate in varList
        // Check existing variables in list for duplicate
        for (int k = 0; k < varList.size(); k++) {
            if (match_results[0] == varList[k].name) { duplicate = true; }
        }
        // If no duplicate in varList found, then push to varList
        if (!duplicate) {
            tempVar.name = match_results[0];
            tempVar.value = "";     // Variable value not instantiated by user
            varList.push_back(tempVar); // Push variable to varList vector
        }
    }
}

//**********************************************************************************************************************
// pushVariable pushes a variable to the variable list during initialization.
//**********************************************************************************************************************
void KnowledgeBase::pushVariable(vector<variable> &varList, smatch &match_results, variable &tempVar){
    tempVar.name = match_results[0];
    tempVar.value = "";     // Variable value not instantiated by user
    varList.push_back(tempVar); // Push variable to varList vector
}

//**********************************************************************************************************************
//
//**********************************************************************************************************************
int KnowledgeBase::getRuleBaseSize(string &mode) {
    int size;
    if(mode == "DIAGNOSTIC")
        size = diagRules.size();
    else if(mode == "REPAIR")
        size = repairRules.size();
    return size;
}
//**********************************************************************************************************************
//
//**********************************************************************************************************************
int KnowledgeBase::getRuleNum(string &mode, int i){
    int num;
    if(mode == "DIAGNOSTIC")
        num = diagRules.at(i).ruleNum;
    else if (mode == "REPAIR")
        num = repairRules.at(i).ruleNum;
    return num;
}
//**********************************************************************************************************************
//
//**********************************************************************************************************************
string KnowledgeBase::getRuleConclusion(string &mode, int i) {
    string conclusion;
    if(mode == "DIAGNOSTIC")
        conclusion = diagRules.at(i).conclusion;
    else if (mode == "REPAIR")
        conclusion = repairRules.at(i).conclusion;
    return conclusion;
}
//**********************************************************************************************************************
//
//**********************************************************************************************************************
int KnowledgeBase::getClauseVarNumber(variable &var){
    int num;
    for(int i = 0; i < repairClauseVarList.size(); i++){
        if(var.name == repairClauseVarList[i].clauseVar){
            num = i + 1;
            break;
        }
            //return i+1;
    }
    return num;
}


//**********************************************************************************************************************
//
//**********************************************************************************************************************
const vector<KnowledgeBase::variable> KnowledgeBase::getRepairVarList(){
    const vector<KnowledgeBase::variable> repairVList = repairVarList;
    return repairVList;
}
//**********************************************************************************************************************
//
//**********************************************************************************************************************
int KnowledgeBase::getClauseVarListSize(string &mode){
    int size;
    if(mode == "DIAGNOSTIC"){
        size = diagClauseVarList.size();
    }
    else if(mode == "REPAIR"){
        size = repairClauseVarList.size();
    }
    return size;
}

//**********************************************************************************************************************
// derives the Rule Number from a given Clause Var List number (REPAIR ONLY)
//**********************************************************************************************************************
int KnowledgeBase::deriveRuleNum(int clauseNum){
    int ruleNum;
    ruleNum = ((clauseNum/(getRuleClauseMax()+1)+1)*10);
    return ruleNum;
}