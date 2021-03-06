// hanoi (河內塔) Edit By Tmr 2000/5/15
// V1.0

#include <ansi.h>
inherit ITEM;

string record="";
int num;
int times=0;
mixed a=allocate(10);
mixed b=allocate(10);
mixed c=allocate(10);
int ma,mb,mc;

int game_reset();
string replace(int arg);

void create()
{
	set_name("河內塔遊戲機",({"hanoi game","game"}) );
	set("long",@long
    一台小型的遊戲機，攜帶方便。你可以看到遊戲機上頭有張小
紙條，上頭寫著一些指令：

.		查看存放圓盤的三根柱子
record		查看你所移動的記錄
reset		重新開始
move x y	移動 x 柱上的圓盤至 y 柱上。

long
);
	set_weight(100);
	set("unit","台");
	set("value",100);
	set("num",3);		//三個盤子
	game_reset();
	setup();
}

// 遊戲重設
int game_reset()
{
	int i,j;
	num=query("num");
	record="";
	times=0;
	ma=num;
	mb=0;
	mc=0;

	for(i=num;i>0;i--) {
		a[num-i+1]=i;
		b[i]=0;
		c[i]=0;
	}

	return 1;	
}

string replace(int arg)
{
	if(arg==0)	return "■";
	return HIG " "+(string)arg+"" NOR;
}

void init()
{
	add_action("do_look",".");
	add_action("do_show","record");
	add_action("do_game_reset","reset");
	add_action("do_move","move");
	add_action("do_set_num","setnum");
}

int do_move(string arg)
{
	string x,y;


        if(!arg || sscanf(arg,"%s %s",x,y)!=2 )
                return notify_fail("輸入格式：move x y。\n");
	if( (x!="a" && x!="b" && x!="c")
	 || (y!="a" && y!="b" && y!="c")	 ||  x==y )
	return notify_fail("輸入參數，只有a,b,c 三種，且兩參數不能相同。\n");
	if(query("move_ok") ) return notify_fail("你已經移動成功\，請reset 重設遊戲。");
	switch(x) {
	case "a":
		if(ma==0) return notify_fail("A 柱上已沒有可供移動的圓盤了。\n");
		switch(y) {
		case "b":
		if(mb==0 ) {
			b[++mb]=a[ma--];
			a[ma+1]=0;
			record +=sprintf("%d : %s -> %s \n",times++,x,y);
			break;
		}
		if (a[ma] > b[mb] ) 
			return notify_fail("移動失敗：B 柱上的圓盤小於 A柱上的圓盤。\n");
		b[++mb]=a[ma--];
		a[ma+1]=0;
		record +=sprintf("%d : %s -> %s \n",times++,x,y);
		break;
		case "c":
		if(mc==0 ) {
			c[++mc]=a[ma--];
			a[ma+1]=0;
			record +=sprintf("%d : %s -> %s \n",times++,x,y);
			break;
		}
		if (a[ma] > c[mc] ) 
			return notify_fail("移動失敗：C 柱上的圓盤小於 A柱上的圓盤。\n");
		c[++mc]=a[ma--];
		a[ma+1]=0;
		record +=sprintf("%d : %s -> %s \n",times++,x,y);
		break;
		}
	break;
	case "b":
		if(mb==0) return notify_fail("B 柱上已沒有可供移動的圓盤了。\n");
		switch(y) {
		case "a":
		if(ma==0 ) {
			a[++ma]=b[mb--];
			b[mb+1]=0;
			record +=sprintf("%d : %s -> %s \n",times++,x,y);
			break;
		}
		if (b[mb] > a[ma] ) 
			return notify_fail("移動失敗：A 柱上的圓盤小於 B柱上的圓盤。\n");
		a[++ma]=b[mb--];
		b[mb+1]=0;
		record +=sprintf("%d : %s -> %s \n",times++,x,y);
		break;
		case "c":
		if(mc==0 ) {
			c[++mc]=b[mb--];
			b[mb+1]=0;
			record +=sprintf("%d : %s -> %s \n",times++,x,y);
		break;
		}
		if (c[mc] > b[mb] ) 
			return notify_fail("移動失敗：C 柱上的圓盤小於 B柱上的圓盤。\n");
		c[++mc]=b[mb--];
		b[mb+1]=0;
		record +=sprintf("%d : %s -> %s \n",times++,x,y);
		break;
		}
	break;
	case "c":
		if(mc==0) return notify_fail("C 柱上已沒有可供移動的圓盤了。\n");
		switch(y) {
		case "a":
		if(ma==0 ) {
			a[++ma]=c[mc--];
			c[mc+1]=0;
		record +=sprintf("%d : %s -> %s \n",times++,x,y);
			break;
		}
		if (c[mc] > a[ma] ) 
			return notify_fail("移動失敗：A 柱上的圓盤小於 C柱上的圓盤。\n");
		a[++ma]=c[mc--];
		c[mc+1]=0;
		record +=sprintf("%d : %s -> %s \n",times++,x,y);
		break;
		case "b":
		if(mb==0 ) {
			b[++mb]=c[mc--];
			c[mc+1]=0;
		record +=sprintf("%d : %s -> %s \n",times++,x,y);
			break;
	}
		if (c[mc] > b[mc] ) 
			return notify_fail("移動失敗：B 柱上的圓盤小於 C柱上的圓盤。\n");
		b[++mb]=c[mc--];
		c[mc+1]=0;
		record +=sprintf("%d : %s -> %s \n",times++,x,y);
		break;
		}

	break;
	}

          if(mb==num) {
           tell_object(this_player(),HIY "你成功\的移動所有的圓盤到B 柱上！！\n" NOR);
          set("move_ok",1);
          }

	write("移動成功\。\n");
        return 1;
}

int do_look()
{
	int i;
	string p="";
	for(i=num;i>0;i--) {
		p +="　"+replace(a[i]) +"　"+ replace(b[i]) +"　"+replace(c[i])+"\n";
	}
	p +=" 　A　 B  C\n";
	write(p+"\n");
	return 1;
}

int do_show()
{
	write("你所移動的記錄：\n");
	write("------------------------------\n");
	write(record+"\n");
	return 1;
}

int do_game_reset()
{
	write("遊戲更新 OK。\n");
	game_reset();
	return 1;
}

int do_set_num(string arg)
{
        int x;
        if(sscanf(arg,"%d",x)!=1 )
                return notify_fail("請輸入數字。\n");
        if( x < 3 || x > 9 )
                return notify_fail("輸入位數範圍在3~9之間。\n");
        set("num",x);
        game_reset();
        write("圓盤重設 OK。\n");
        return 1;
}
