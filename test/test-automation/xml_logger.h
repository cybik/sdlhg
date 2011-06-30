#ifndef _XML_LOGGER_H
#define _XML_LOGGER_H

#include "logger.h"

/*!
 * Prints out information about starting the test run in XML
 *
 * \param parameterCount How many parameters were given
 * \param runnerParameters What parameters were given to the runner
 * \param eventTime When the execution started
 * \param data Any additional data logger needs
 */
void XMLRunStarted(int parameterCount, char *runnerParameters[], time_t eventTime, void *data);

/*!
 * Prints out information about ending the test run in XML
 *
 * \param testCount How many tests were executed in total
 * \param suiteCount How many suite were executed in total
 * \param testPassCount How many tests passed in total
 * \param testFailCount How many tests failed in total
 * \param endTime When the execution ended
 * \param totalRuntime How long the execution took
 */
void XMLRunEnded(int testCount, int suiteCount, int testPassCount, int testFailCount,
                 time_t endTime, double totalRuntime);

/*!
 * Prints the data about the test suite that'll be executed next in XML
 *
 * \param suiteName Name of the test suite
 * \param eventTime When the execution starts
 */
void XMLSuiteStarted(const char *suiteName, time_t eventTime);

/*!
 * Prints information about the test suite that was just executed in XML
 *
 * \param testsPassed how many tests passed from this suite
 * \param testsFailed how many tests failed from this suite
 * \param testsSkipped how many tests were skipped (not implemented)
 * \param endTime When the suite execution ended
 * \param totalRuntime How long did the suite's execution take
 */
void XMLSuiteEnded(int testsPassed, int testsFailed, int testsSkipped,
           time_t endTime, double totalRuntime);

/*!
 * Prints the data about the test test that'll be executed next in XML
 *
 * \param testName Name of the test that'll be executed
 * \param suiteName Name of the suite of the test
 * \param testDescription Description of the test
 * \param startTime When the test started to execute
 */
void XMLTestStarted(const char *testName, const char *suiteName, const char *testDescription, time_t startTime);

/*!
 * Prints information about the test test that was just executed in XML
 *
 * \param testName Name of the executed test
 * \param suiteName Name of the suite of the test
 * \param testResult Did the test fail (!= 0) or pass (== 0)
 * \param endTime When the test execution ended
 * \param totalRuntime Total runtime of the executed test
 */
void XMLTestEnded(const char *testName, const char *suiteName,
          int testResult, time_t endTime, double totalRuntime);

/*!
 * Prints information about plain assert in XML
 *
 * \param assertName Name of the assert
 * \param assertResult Did assert fail (== 0) or success (!= 0)
 * \param assertMessage Message of the assert
 * \param eventTime When the assert happened
 */
void XMLAssert(const char *assertName, int assertResult, const char *assertMessage,
			time_t eventTime);

/*!
 * Prints information about assert that has actual and expected values in XML
 *
 * \param assertName Name of the assert
 * \param assertResult Did assert fail (== 0) or success (!= 0)
 * \param assertMessage Message of the assert
 * \param actualValue Actual value of assert
 * \param expected Excepted value of assert
 * \param eventTime When the assert happened
 */
void XMLAssertWithValues(const char *assertName, int assertResult, const char *assertMessage,
		int actualValue, int expected, time_t eventTime);

/*!
 * Prints summary of all assertions of certain tests in XML
 *
 * \param numAsserts Total assert count for the executed test
 * \param numAssertsFailed Count of failed asserts in the test
 * \param numAssertsPass Count of passed asserts in the test
 * \param eventTime Timestamp of the summary
 */
void XMLAssertSummary(int numAsserts, int numAssertsFailed, int numAssertsPass, time_t eventTime);

/*!
 * Prints given message in XML
 *
 * \param logMessage Message to be logged
 * \param eventTime Timestamp for log message
 */
void XMLLog(const char *logMessage, time_t eventTime);

#endif
