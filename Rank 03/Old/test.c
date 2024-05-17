int	main(void)
{
	char *c = "hello";

	while (1)
	{
		write(1, c, 1);
		c++;
	}
	return (0);
}
