#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

struct Season
{
  std::string_view name{};
  double averageTemperature{};
};

int main()
{
  std::array<Season, 4> seasons{
    { { "Spring", 285.0 },
      { "Summer", 296.0 },
      { "Fall", 288.0 },
      { "Winter", 263.0 } }
  };

  // We can compare averageTemperature of the two arguments to
  // sort the array.
  // std::sort(seasons.begin(), seasons.end(),
  //           [](const auto& a, const auto& b) {
  //             return (a.averageTemperature < b.averageTemperature);
  //           });

  std::sort(seasons.begin(), seasons.end(),
          [](Season s1, Season s2) {
            return (s1.averageTemperature < s2.averageTemperature);
          });

  for (const auto& season : seasons)
  {
    std::cout << season.name << '\n';
  }

  return 0;
}