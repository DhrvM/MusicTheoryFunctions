#include <iostream>
#include <string>
#include <vector>

class Chord_Finder {
 public:
  // Constructor
  Chord_Finder(std::string root, int type) : root_(root), type_(type) {}

  // Print the Chord notes
  void PrintChord() const {
    std::cout << "Chord notes: ";
    for (int i = 0; i < Chord_.size(); ++i) {
      std::cout << Chord_[i] << " ";
    }
    std::cout << std::endl;
  }

  // Calculate the chord notes
  void CalculateChord() {
    // Convert the root note to an index (0-11)
    int root_index = 0;
    for (int i = 0; i < 12; ++i) {
      if (notes_[i] == root_) {
        root_index = i;
        break;
      }
    }

    // Calculate the Chord notes based on the root and type
    switch (type_) {
      case 1:  // Major
        Chord_ = {root_, notes_[(root_index + 4) % 12], notes_[(root_index + 7) % 12]};
        break;
      case 2:  // Minor
        Chord_ = {root_, notes_[(root_index + 3) % 12], notes_[(root_index + 7) % 12]};
        break;
      case 3:  // Diminished
        Chord_ = {root_, notes_[(root_index + 3) % 12], notes_[(root_index + 6) % 12]};
        break;
      case 4:  // Augmented
        Chord_ = {root_, notes_[(root_index + 4) % 12], notes_[(root_index + 8) % 12]};
        break;
      default:
        std::cout << "Invalid Chord type" << std::endl;
        break;
    }
  }

 private:
  std::string root_;
  int type_;
  std::string notes_[12] = {"C", "C#", "D", "Eb", "E", "F", "F#", "G", "Ab", "A", "Bb", "B"};
  std::vector<std::string> Chord_;
};

int main() {
  std::string root;
  int type;

//Input Chord Root Note
  std::cout << "Enter Scale Root: ";
  std::getline(std::cin, root);

//Input Chord Type
  std::cout << "Enter Chord Type: ";
  std::cout << "\n 1. Major ";
  std::cout << "\n 2. Minor ";
  std::cout << "\n 3. Diminished ";
  std::cout << "\n 4. Augmented \n";
  std::cin >>type;

Chord_Finder S(root,type);
S.CalculateChord();
S.PrintChord();

return 0;
}