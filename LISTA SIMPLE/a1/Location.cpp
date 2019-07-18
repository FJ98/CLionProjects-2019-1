#include <utility>
// Created by ruben on 4/5/19.
#include "Location.h"

// Defina los metodos que crea necesario
Location::Location(int position_id, std::string state_code, std::string county, double latitude, double longitude,
                   std::string line, std::string construction) : position_id(position_id),
                   state_code(std::move(state_code)),county(std::move(county)), latitude(latitude),
                   longitude(longitude), line(std::move(line)), construction(std::move(construction)) {

}
