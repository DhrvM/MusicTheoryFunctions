#include <iostream>
#include <string>
#include <vector>

class Scale_Finder {
 public:
  // Constructor
  Scale_Finder(std::string root, int type) : root_(root), type_(type) {}

  // Print the scale notes
  void PrintScale() const {
    std::cout << "Scale notes: ";
    for (int i = 0; i < scale_.size(); ++i) {
      std::cout << scale_[i] << " ";
    }
    std::cout << std::endl;
  }

  // Calculate the scale notes
  void CalculateScale() {
    // Convert the root note to an index (0-11)
    int root_index = 0;
    for (int i = 0; i < 12; ++i) {
      if (notes_[i] == root_) {
        root_index = i;
        break;
      }
    }

    // Calculate the scale notes based on the root and type
    switch (type_) {
      case 1:  // Major
        scale_ = {root_, notes_[(root_index + 2) % 12], notes_[(root_index + 4) % 12],
                  notes_[(root_index + 5) % 12], notes_[(root_index + 7) % 12],
                  notes_[(root_index + 9) % 12], notes_[(root_index + 11) % 12]};
        break;
      case 2:  // Minor
        scale_ = {root_, notes_[(root_index + 2) % 12], notes_[(root_index + 3) % 12],
                  notes_[(root_index + 5) % 12], notes_[(root_index + 7) % 12],
                  notes_[(root_index + 8) % 12], notes_[(root_index + 10) % 12]};
        break;
      case 3:  // Harmonic Minor
        scale_ = {root_, notes_[(root_index + 2) % 12], notes_[(root_index + 3) % 12],
                  notes_[(root_index + 5) % 12], notes_[(root_index + 7) % 12],
                  notes_[(root_index + 8) % 12], notes_[(root_index + 11) % 12]};
        break;
      default:
        std::cout << "Invalid scale type" << std::endl;
        break;
    }
  }

 private:
  std::string root_;
  int type_;
  std::string notes_[12] = {"C", "C#", "D", "Eb", "E", "F", "F#", "G", "Ab", "A", "Bb", "B"};
  std::vector<std::string> scale_;
};

int main() {
  std::string root;
  int type;

//Input Scale Root Note
  std::cout << "Enter Scale Root: ";
  std::getline(std::cin, root);

//Input Scale Type
  std::cout << "Enter Scale Type: ";
  std::cout << "\n 1. Major ";
  std::cout << "\n 2. Minor ";
  std::cout << "\n 3. Harmonic Minor \n";
  std::cin >>type;

Scale_Finder S(root,type);
S.CalculateScale();
S.PrintScale();

return 0;
}