/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:07:59 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/20 15:41:26 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//[🍵] mlx hook : 【按键函数】和【松键函数】
//[🍵]-- 初始化 wasd键位 ：0 -->
// 🍵<!-- 按键函数：如果被按的键位，比如w，值为0，那就把它设置为1 -->
// 🍵<!-- 松键函数：如果被松的键位，比如w，值为1，那就把它设置为0 --> -->
// - [ ] mlx loop hook : 【画图函数】和【键位操作函数】
// <!-- 画图函数：根据数据画图， 比如（10，10）在x：10和y：10的位置画一个方块 -->
// <!-- 键位操作函数：根据按键改变数据，比如按了w，y数据减1 -->
// <!-- 总体解释：原数据x：10和y：10，（10，10）方位画着一个方块方块。我按了一下w和a键，x和y都数据都产生了改变：x--和y--，图像会在（9，9）都方位重新画一个方块，（原（10，10）的方块被覆盖了）-->

t_key  *init_key(void)
{
    t_key *key;

    key = malloc(sizeof(t_key));
    if (!key)
      return (NULL);
    key->w = 0;
    key->a = 0;
    key->s = 0;
    key->d = 0;
    return (key);
}

int key_press(int keycode, t_vars *vars)
{
  if (keycode == KEY_ESC)
    __close__(vars);
  if (keycode == KEY_W && vars->key->w == 0)
  {
    vars->key->w = 1;
  }
  else if (keycode == KEY_A && vars->key->a == 0)
    vars->key->a = 1;
  else if (keycode == KEY_S && vars->key->s == 0)
    vars->key->s = 1;
  else if (keycode == KEY_D && vars->key->d == 0)
    vars->key->d = 1;
  return (1);
}

int key_release(int keycode, t_vars *vars)
{
  if (keycode == KEY_ESC)
    __close__(vars);
  if (keycode == KEY_W && vars->key->w == 1)
    vars->key->w = 0;
  else if (keycode == KEY_A && vars->key->a == 1)
    vars->key->a = 0;
  else if (keycode == KEY_S && vars->key->s == 1)
    vars->key->s = 0;
  else if (keycode == KEY_D && vars->key->d == 1)
    vars->key->d = 0;
  return (1);
}

void   key_mouv(t_vars *vars) //【键位操作函数】
{
  if (vars->key->w == 1)
  {
    // printf("w\n");
    if (vars->mouv->y > 100)
    {
        vars->mouv->y -= 1;
        printf("W : [%d]\n", vars->mouv->y);
    }
  }
  else if (vars->key->a == 1)
  {
    // printf("a\n");
    if (vars->mouv->x > 100)
    {
      vars->mouv->x -= 1;
      printf("A : [%d]\n", vars->mouv->x);
    }
  }
  else if (vars->key->s == 1)
   {
  //  printf("s\n");
    if (vars->mouv->y < 1000)
    {
      vars->mouv->y += 1;
      printf("S : [%d]\n", vars->mouv->y);
    }
   }
  else if (vars->key->d == 1)
   {
    //  printf("d\n");
    if (vars->mouv->x < 1000)
    {
      vars->mouv->x += 1;
      printf("D : [%d]\n", vars->mouv->x);
    }
   }
}

void draw_wall(t_vars *vars)
{
  
  // (X position * 4 + 4 * Line size * Y position)  像数的地址指针
  //my_mlx_pixel_put(vars, x, y, 0x000000FF) 找到点放上颜色
   int x_i = 0;
	 int y_i;  
	while (x_i < 1000)
	{

		y_i = 0;
		while (y_i  < 1000)
		{
     
      my_mlx_pixel_put(vars,  x_i,  y_i, 0x000000FF);
      y_i += 1;
		
			 //找到点放上颜色
		}
		x_i += 1;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0); //上传图片到窗口
	
	 //mlx_key_hook(vars->win, key_hook, vars);  //键盘设置
                            
}


//img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
void draw_pixe(t_vars *vars)
{
  
  // (X position * 4 + 4 * Line size * Y position)  像数的地址指针
  //my_mlx_pixel_put(vars, x, y, 0x000000FF) 找到点放上颜色
   int x_i = 0;
	 int y_i;  
	while ((vars->mouv->x) + x_i  < 100 + vars->mouv->x)
	{

		y_i = 0;
		while ((vars->mouv->y) + y_i  < 100 + vars->mouv->y)
		{
     
      my_mlx_pixel_put(vars,  vars->mouv->x + x_i,  vars->mouv->y + y_i, 0x00000000);
      y_i += 1;
		
			 //找到点放上颜色
		}
		x_i += 1;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0); //上传图片到窗口
	
	 //mlx_key_hook(vars->win, key_hook, vars);  //键盘设置
                            
}

int	event_loop(t_vars *vars)
{
  draw_wall(vars);
  draw_pixe(vars);
  // mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0); //上传图片到窗口
  key_mouv(vars);
	return (1);
}

