#!/bin/sh
make
echo "check mandatory\n\n\n"
echo "check bad_extension.kub"
valgrind ./Cub3D maps/mandatory/error/bad_extension.kub 2>check_val
checker=`<check_val grep "All heap blocks were freed"`
if [ -z "$checker" ]
then
	cat check_val
else
	echo "No leaks ✅"
fi
rm check_val
sleep 1
echo "check big_error.cub"
valgrind ./Cub3D maps/mandatory/error/big_error.cub 2>check_val
checker=`<check_val grep "All heap blocks were freed"`
if [ -z "$checker" ]
then
	cat check_val
else
	echo "No leaks ✅"
fi
rm check_val
sleep 1
echo "check door_error.cub"
valgrind ./Cub3D maps/mandatory/error/door_error.cub 2>check_val
checker=`<check_val grep "All heap blocks were freed"`
if [ -z "$checker" ]
then
	cat check_val
else
	echo "No leaks ✅"
fi
rm check_val
sleep 1
echo "check double_spawn.cub"
valgrind ./Cub3D maps/mandatory/error/double_spawn.cub 2>check_val
checker=`<check_val grep "All heap blocks were freed"`
if [ -z "$checker" ]
then
	cat check_val
else
	echo "No leaks ✅"
fi
rm check_val
sleep 1
echo "check letterz.cub"
valgrind ./Cub3D maps/mandatory/error/letterz.cub 2>check_val
checker=`<check_val grep "All heap blocks were freed"`
if [ -z "$checker" ]
then
	cat check_val
else
	echo "No leaks ✅"
fi
rm check_val
sleep 1
echo "check missing_arg_error.cub"
valgrind ./Cub3D maps/mandatory/error/missing_arg_error.cub 2>check_val
checker=`<check_val grep "All heap blocks were freed"`
if [ -z "$checker" ]
then
	cat check_val
else
	echo "No leaks ✅"
fi
rm check_val
sleep 1
echo "check missing_walls_col_error.cub"
valgrind ./Cub3D maps/mandatory/error/missing_walls_col_error.cub 2>check_val
checker=`<check_val grep "All heap blocks were freed"`
if [ -z "$checker" ]
then
	cat check_val
else
	echo "No leaks ✅"
fi
rm check_val
sleep 1
echo "check missing_walls_line_error.cub"
valgrind ./Cub3D maps/mandatory/error/missing_walls_line_error.cub 2>check_val
checker=`<check_val grep "All heap blocks were freed"`
if [ -z "$checker" ]
then
	cat check_val
else
	echo "No leaks ✅"
fi
rm check_val
sleep 1
echo "check missing_xpm_error.cub"
valgrind ./Cub3D maps/mandatory/error/missing_xpm_error.cub 2>check_val
checker=`<check_val grep "All heap blocks were freed"`
if [ -z "$checker" ]
then
	cat check_val
else
	echo "No leaks ✅"
fi
rm check_val
sleep 1
echo "check to_much_arg.cub"
valgrind ./Cub3D maps/mandatory/error/to_much_arg.cub 2>check_val
checker=`<check_val grep "All heap blocks were freed"`
if [ -z "$checker" ]
then
	cat check_val
else
	echo "No leaks ✅"
fi
rm check_val
sleep 1
echo "Check Bonus\n\n\n\n\n"
make bonus
echo "check bad_extension.kub"
valgrind ./Cub3D_Bonus maps/bonus/error/bad_extension.kub 2>check_val
checker=`<check_val grep "All heap blocks were freed"`
if [ -z "$checker" ]
then
	cat check_val
else
	echo "No leaks ✅"
fi
rm check_val
sleep 1
echo "check big_error.cub"
valgrind ./Cub3D_Bonus maps/bonus/error/big_error.cub 2>check_val
checker=`<check_val grep "All heap blocks were freed"`
if [ -z "$checker" ]
then
	cat check_val
else
	echo "No leaks ✅"
fi
rm check_val
sleep 1
echo "check door_error.cub"
valgrind ./Cub3D_Bonus maps/bonus/error/door_error.cub 2>check_val
checker=`<check_val grep "All heap blocks were freed"`
if [ -z "$checker" ]
then
	cat check_val
else
	echo "No leaks ✅"
fi
rm check_val
sleep 1
echo "check double_spawn.cub"
valgrind ./Cub3D_Bonus maps/bonus/error/double_spawn.cub 2>check_val
checker=`<check_val grep "All heap blocks were freed"`
if [ -z "$checker" ]
then
	cat check_val
else
	echo "No leaks ✅"
fi
rm check_val
sleep 1
echo "check letterz.cub"
valgrind ./Cub3D_Bonus maps/bonus/error/letterz.cub 2>check_val
checker=`<check_val grep "All heap blocks were freed"`
if [ -z "$checker" ]
then
	cat check_val
else
	echo "No leaks ✅"
fi
rm check_val
sleep 1
echo "check missing_arg_error.cub"
valgrind ./Cub3D_Bonus maps/bonus/error/missing_arg_error.cub 2>check_val
checker=`<check_val grep "All heap blocks were freed"`
if [ -z "$checker" ]
then
	cat check_val
else
	echo "No leaks ✅"
fi
rm check_val
sleep 1
echo "check missing_walls_col_error.cub"
valgrind ./Cub3D_Bonus maps/bonus/error/missing_walls_col_error.cub 2>check_val
checker=`<check_val grep "All heap blocks were freed"`
if [ -z "$checker" ]
then
	cat check_val
else
	echo "No leaks ✅"
fi
rm check_val
sleep 1
echo "check missing_walls_line_error.cub"
valgrind ./Cub3D_Bonus maps/bonus/error/missing_walls_line_error.cub 2>check_val
checker=`<check_val grep "All heap blocks were freed"`
if [ -z "$checker" ]
then
	cat check_val
else
	echo "No leaks ✅"
fi
rm check_val
sleep 1
echo "check missing_xpm_error.cub"
valgrind ./Cub3D_Bonus maps/bonus/error/missing_xpm_error.cub 2>check_val
checker=`<check_val grep "All heap blocks were freed"`
if [ -z "$checker" ]
then
	cat check_val
else
	echo "No leaks ✅"
fi
rm check_val
sleep 1
make fclean
