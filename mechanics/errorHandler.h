//
// Created by menox on 19.06.2023.
//

#ifndef TAMAGOTCHI_ERRORHANDLER_H
#define TAMAGOTCHI_ERRORHANDLER_H

// C++
#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <filesystem>
#include <ctime>

enum class errorCode {
    Unspecified,
    OutOfRange,
    FileError,
    ValidationError,
    FoodDoesNotExist,
    EmptyString,
    TextureNotFound,
    SoundNotFound,
    FontNotFound
};

/**
 * @brief The error handler class
 */
class errorHandler : public std::exception{
private:
    errorCode code; // The error code
    std::ofstream logFile;

public:
    /**
     * @brief Constructor for the error handler
     * @param code The error code
     */
    explicit errorHandler(errorCode code = errorCode::Unspecified);

    /**
     * @brief Destructor for the error handler
     */
    ~errorHandler();

    /**
     * @brief Returns the error code
     * @return The error code
     */
    errorCode getErrorCode() const;

    /**
     * @brief Returns the error message
     */
    [[nodiscard]] std::string getErrorMessage();

    /**
     * @brief Logs the error message to a file
     */
    void logError();
};


#endif //TAMAGOTCHI_ERRORHANDLER_H
