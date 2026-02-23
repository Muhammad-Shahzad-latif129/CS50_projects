-- Keep a log of any SQL queries you execute as you solve the mystery.

-- crimes happen on 28 july 2025 at Humphery Street:
SELECT * FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';

-- To get in which the transcripts include the word bakery
SELECT * FROM interviews WHERE transcript LIKE '%bakery%' AND month = 7 AND day = 28;

-- From bakery security logs getting the information of all the exits
 SELECT * FROM bakery_security_logs WHERE year = 2025 AND month = 7 AND day = 28 AND  hour = 10 AND minute <= 25 AND activity = 'exit';

-- Getting the information of the withdraws occur on the theft day location Leggett Street
 SELECT * FROM atm_transactions WHERE atm_location = 'Leggett Street' AND month = 7 AND day = 28 AND transaction_type = 'withdraw';

 -- Getting the account_nubmer from the bank_accounts of all the transaction occur on the theft day at the atm 
 SELECT * FROM bank_accounts WHERE account_number IN (
SELECT account_number FROM atm_transactions WHERE atm_location = 'Leggett Street' AND month = 7 AND day = 28 AND transaction_type = 'withdraw');

-- Getting the phone calls information happen on the theft day duration < 60
SELECT * FROM phone_calls WHERE year = 2025 AND month = 7 AND day = 28 AND duration < 60;

-- To get the id of the airport and the ciyt 
SELECT * FROM airports WHERE city = 'Fiftyville';

-- Flights information that have origin air pot id = 8 and very first flight as in the transcript
SELECT * FROM flights WHERE origin_airport_id IN (SELECT id FROM airports WHERE city = 'Fiftyville') AND day = 29 AND year = 2025 AND month = 7 ORDER BY hour ASC LIMIT 1;

-- To get the information of the people that have same the license plate that exit on the theft day from bakery
SELECT * FROM people WHERE license_plate IN(
SELECT license_plate FROM bakery_security_logs WHERE 
 year = 2025 AND month = 7 AND day = 28 AND hour = 10 AND minute <= 25 AND activity = 'exit');

-- Get information of the passengers that exit from the bakery on the theft day
 SELECT * FROM passengers WHERE flight_id IN (SELECT id FROM flights WHERE origin_airport_id IN (SELECT id FROM airports WHERE city = 'Fiftyville') AND day = 29 AND year = 2025 AND month =
 7) AND passport_number IN (SELECT passport_number FROM people WHERE license_plate IN(
SELECT license_plate FROM bakery_security_logs WHERE 
year = 2025 AND month = 7 AND day = 28 AND hour = 10 AND minute <= 25 AND activity = 'exit')
);

-- getting the name of the person that have the phone number '(375) 555-8161' as he is the accomplice
SELECT * FROM people WHERE phone_number = '(375) 555-8161';