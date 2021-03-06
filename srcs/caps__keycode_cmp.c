#include "libft.h"
#include "types.h"

int			caps__keycode_cmp(const t_buffer keycode1, const t_buffer keycode2)
{
	size_t	size;
	size_t	i;

	if (keycode1.size != keycode2.size)
		return (keycode1.size - keycode2.size);
	size = keycode1.size;
	if (size > 2)
		i = 2;
	else
		i = 0;
	while (i < size)
	{
		if (keycode1.bytes[i] != keycode2.bytes[i])
			break ;
		i++;
	}
	if (i == size)
		return (0);
	return (keycode1.bytes[i] - keycode2.bytes[i]);
}
