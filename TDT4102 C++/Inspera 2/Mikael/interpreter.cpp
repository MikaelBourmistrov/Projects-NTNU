#include "interpreter.h"


// Task S1: Color name mapping
//
// This function takes the name of a color as its argument and
// returns the corresponding Graph_lib color type. This function is
// needed to convert the color names given as strings in the
// instruction code to the internal color representation used by the
// graphics library. We provide the map color_map, defined in
// interpreter.h that contains all valid mappings between color
// names and color types.
Color Interpreter::get_color(string color_name) 
{
  // BEGIN: S1
  //
  // Write your answer to assignment S1 here, between the // BEGIN: S1
  // and // END: S1 comments. You should remove any code that is
  // already there and replace it with your own.

  if(color_map.find(color_name) == color_map.end()){
    throw invalid_argument("The color '" + color_name + "' is not a valid color.");
  }
  
  return color_map.at(color_name);

  // END: S1
}

// Task S2: Instruction interpretation
//
// The interpreter function Interpreter::execute_instruction()
// reads an instruction (refer to the table in the
// assignment PDF for a description) and calls the corresponding
// function in the RobotGrid class to perform the requested action
// for changing the universe
void Interpreter::execute_instruction(istringstream instruction)
{
  // BEGIN: S2
  //
  // Write your answer to assignment S2 here, between the // BEGIN: S2
  // and // END: S2 comments.
  // You may use the code below as a starting point for your
  // implementation following the structure of the implementation of
  // the make_grid command or you may start from scratch. If you use
  // this code as a starting point, replace each of the throw
  // string("Not implemented " + cmd); lines with your implementation.

  string instr;
  instruction >> instr;
  if (instr == "make_grid") {
    int rows;
    int cols;

    instruction >> rows;
    instruction >> cols;

    grid.make_grid(rows, cols);

  } else if (instr == "make_robot") {
    string name, color;
    int x_pos, y_pos;

    instruction >> name;
    instruction >> x_pos;
    instruction >> y_pos;
    instruction >> color;

    grid.make_robot(name, {x_pos, y_pos}, get_color(color));

  } else if (instr == "clear_robots") {
    grid.clear_robots();

  } else if (instr == "move_robot") {
    string name;
    int new_x_pos, new_y_pos;

    instruction >> name;
    instruction >> new_x_pos;
    instruction >> new_y_pos;

    grid.move_robot(name, {new_x_pos, new_y_pos});
    
  } else if (instr == "recolor_robot") {
    string name, color;

    instruction >> name;
    instruction >> color;

    grid.recolor_robot(name, get_color(color));

  } else if (instr == "rename_robot") {
    string name, new_name;

    instruction >> name;
    instruction >> new_name;

    grid.rename_robot(name, new_name);

  } else if (instr == "delete_robot") {
    string name;

    instruction >> name;

    grid.delete_robot(name);

  } else {
    // Don't change this
    throw string("Invalid command " + instr);
  }

  (void)grid;

  // END: S2
}

// |
// | END OF ASSIGNMENTS
// |

Interpreter::Interpreter(RobotGrid &grid) : grid(grid) 
{
}
