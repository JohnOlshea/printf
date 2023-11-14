/**
 * word_count - Counts characters
 *
 * @string: strint to count
 *
 * Return: characters counted
 */
int word_count(char *string)
{
	int i = 0;

	while(*string != '\0')
	{
		i++;
		string++;
	}
	return (i);
}
