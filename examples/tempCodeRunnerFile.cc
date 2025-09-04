bool isPrime(int number)
{
    if (number <= 1)
        return false;
    else if (number <= 3)
        return true;
    else if (number % 2 == 0 || number % 3 == 0)
        return false;

    int limit = (int)sqrt(number);
    for (int i = 5; i <= limit; i += 6)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}