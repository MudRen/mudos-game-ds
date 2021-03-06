// guess game (猜數字遊戲) Edit By Tmr 2000/5/15
// V1.0

#include <ansi.h>
inherit ITEM;

string record="";
int num;
int times=0;
string math;
mixed *a=allocate(11);
int game_reset();

void create()
{
	set_name("猜數字遊戲機",({"guess game","game"}) );
	set("long",@long
    一台小型的遊戲機，攜帶方便。你可以看到遊戲機上頭有張小
紙條，上頭寫著一些指令：

.		所猜數字列表
reset		重新開始
guess x		猜數字
setnum	x	設字所要猜的位數 (4~10)

long
);
	set_weight(100);
	set("unit","台");
	set("value",100);
	set("num",4);		//四位數
	game_reset();
	setup();
}

// 遊戲重設
int game_reset()
{
	int i,j,temp,max;

	math="";
	record="";
	max=10;
	times=0;
	num=query("num");
	set("guess_ok",0);
	for(i=0;i<10;i++) a[i]=i;

	for(i=0;i<num;i++) {	// 設定迷底數字
		j=random(max--);
		temp=a[j];	a[j]=a[max];	a[max]=temp;
		math +=(string)a[max];
	}
	if( wizardp(this_player()) )
		 write("[ WIZARD ]  "+math+"\n");
	return 1;	
}

void init()
{
	add_action("do_show",".");
	add_action("do_game_reset","reset");
	add_action("do_guess","guess");
	add_action("do_set_num","setnum");
}


int do_show()
{
	write("你所猜的數字：\n");
	write("------------------------------\n");
	write(record+"\n");
	return 1;
}

int do_game_reset()
{
	game_reset();
	write("遊戲重設 OK\n");
	return 1;
}

int do_guess(string arg)
{
	int i,j,a,b;
	a=0;	b=0;

	if (!arg)
		return notify_fail("指令格式：guess 數字。\n");
	if( strlen(arg)  != num  )
		return notify_fail("目前為"+(string)num+" 位數猜測，請輸入正確的位數。\n");

	if(query("guess_ok") )
		return notify_fail("你已猜對數字，請reset 重新設定遊戲。\n");
          for (i=0;i<num;i++) {
                  for (j=0;j<num;j++)
		if(i!=j && arg[i]==arg[j] ) return notify_fail("所猜數字中，不能有重覆。\n");
          }

	for (i=0;i<num;i++) {
	if( arg[i]==math[i] ) a++;
	else	for(j=0;j<num;j++)
			if( math[j]==arg[i] ) b++;
	}
	write(sprintf("%dA %dB\n",a,b) );
	if(a==num && b==0) {
	tell_object(this_player(),HIG "恭喜你成功\的猜對了數字！！\n" NOR );
	record +=sprintf(HIY "%d : %s -> %dA %dB\n" NOR,++times,arg,a,b);
	set("guess_ok",1);
	return 1;
	}
	record +=sprintf("%d : %s -> %dA %dB\n",++times,arg,a,b);
	return 1;
}

int do_set_num(string arg)
{
	int x;
  if(!arg) return notify_fail("請輸入數字。\n");
        if(sscanf(arg,"%d",x)!=1 )
		return notify_fail("請輸入數字。\n");
	if( x < 4 || x > 10 )
		return notify_fail("輸入位數範圍在4~9之間。\n");
	set("num",x);
	game_reset();
	write("位數重設 OK。\n");
	return 1;
}
