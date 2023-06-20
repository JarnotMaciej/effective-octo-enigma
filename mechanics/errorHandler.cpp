//
// Created by menox on 19.06.2023.
//

#include "errorHandler.h"

errorHandler::errorHandler(errorCode code) {
    this->code = code;

    // Open the log file
    std::filesystem::path logFilePath = std::filesystem::current_path().parent_path() / "error_log.txt";

    try {
        this->logFile.open(logFilePath, std::ios::app);
    } catch (std::exception &e) {
        std::cout << "Error opening log file: " << e.what() << std::endl;
    }

    logError();
}

errorCode errorHandler::getErrorCode() const {
    return this->code;
}

std::string errorHandler::getErrorMessage() {
    std::string errorString;
    switch (this->code) {
        case errorCode::Unspecified:
            errorString = "Unspecified error";
            break;
        case errorCode::OutOfRange:
            errorString = "Out of range";
            break;
        case errorCode::FileError:
            errorString = "File error";
            break;
        case errorCode::EmptyString:
            errorString = "Empty String";
            break;
        case errorCode::ValidationError:
            errorString = "Validation error";
            break;
        case errorCode::TextureNotFound:
            errorString = "Texture not found";
            break;
        case errorCode::SoundNotFound:
            errorString = "Sound not found";
            break;
        case errorCode::FontNotFound:
            errorString = "Font not found";
            break;
        default:
            errorString = "Unknown error";
            break;
    }

    return errorString;
}

void errorHandler::logError() {
    std::time_t currentTime = std::time(nullptr);
    std::tm *localTime = std::localtime(&currentTime);

    //    std::string timeString = std::to_string(localTime->tm_mday) + "." + std::to_string(localTime->tm_mon + 1) + "." + std::to_string(localTime->tm_year + 1900) + " " + std::to_string(localTime->tm_hour) + ":" + std::to_string(localTime->tm_min) + ":" + std::to_string(localTime->tm_sec);
    //    std::string timeString in format DD.MM.YYYY HH:MM:SS
    std::string timeString;
    if (localTime->tm_mday < 10) {
        timeString += "0";
    }
    timeString += std::to_string(localTime->tm_mday) + ".";
    if (localTime->tm_mon + 1 < 10) {
        timeString += "0";
    }
    timeString += std::to_string(localTime->tm_mon + 1) + "." + std::to_string(localTime->tm_year + 1900) + " ";
    if (localTime->tm_hour < 10) {
        timeString += "0";
    }
    timeString += std::to_string(localTime->tm_hour) + ":";
    if (localTime->tm_min < 10) {
        timeString += "0";
    }
    timeString += std::to_string(localTime->tm_min) + ":";
    if (localTime->tm_sec < 10) {
        timeString += "0";
    }
    timeString += std::to_string(localTime->tm_sec);

    // Check if the log file is open before writing to it
    if (logFile.is_open()) {
        logFile << timeString << " - " << this->getErrorMessage() << std::endl;
    }

}

errorHandler::~errorHandler() {
    // Close the log file
    if (logFile.is_open()) {
        logFile.close();
    }
}

void errorHandler::printError() {
    std::cout << this->getErrorMessage() << std::endl;
}
