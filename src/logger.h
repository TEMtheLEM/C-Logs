/**
 * @file logger.h
 * @author Connor Inch  <conninch@protonmail.com>
 * @brief The header needed to use this library.
 * @version 1.0
 * @date 2022-02-05
 * 
 * @copyright Copyright (c) Connor Inch 2022
 */

#pragma once

void Log(const char *msg_clr, const char *msg, const char *suff_clr, const char *suff);
void LogInfo(const char *msg);
void LogOk(const char *msg);
void LogWarning(const char *msg);
void LogError(const char *msg);

// End of logger.h
