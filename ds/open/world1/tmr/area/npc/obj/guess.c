// guess game (�q�Ʀr�C��) Edit By Tmr 2000/5/15
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
	set_name("�q�Ʀr�C����",({"guess game","game"}) );
	set("long",@long
    �@�x�p�����C�����A��a��K�C�A�i�H�ݨ�C�����W�Y���i�p
�ȱ��A�W�Y�g�ۤ@�ǫ��O�G

.		�Ҳq�Ʀr�C��
reset		���s�}�l
guess x		�q�Ʀr
setnum	x	�]�r�ҭn�q����� (4~10)

long
);
	set_weight(100);
	set("unit","�x");
	set("value",100);
	set("num",4);		//�|���
	game_reset();
	setup();
}

// �C�����]
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

	for(i=0;i<num;i++) {	// �]�w�g���Ʀr
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
	write("�A�Ҳq���Ʀr�G\n");
	write("------------------------------\n");
	write(record+"\n");
	return 1;
}

int do_game_reset()
{
	game_reset();
	write("�C�����] OK\n");
	return 1;
}

int do_guess(string arg)
{
	int i,j,a,b;
	a=0;	b=0;

	if (!arg)
		return notify_fail("���O�榡�Gguess �Ʀr�C\n");
	if( strlen(arg)  != num  )
		return notify_fail("�ثe��"+(string)num+" ��Ʋq���A�п�J���T����ơC\n");

	if(query("guess_ok") )
		return notify_fail("�A�w�q��Ʀr�A��reset ���s�]�w�C���C\n");
          for (i=0;i<num;i++) {
                  for (j=0;j<num;j++)
		if(i!=j && arg[i]==arg[j] ) return notify_fail("�Ҳq�Ʀr���A���঳���СC\n");
          }

	for (i=0;i<num;i++) {
	if( arg[i]==math[i] ) a++;
	else	for(j=0;j<num;j++)
			if( math[j]==arg[i] ) b++;
	}
	write(sprintf("%dA %dB\n",a,b) );
	if(a==num && b==0) {
	tell_object(this_player(),HIG "���ߧA���\\���q��F�Ʀr�I�I\n" NOR );
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
  if(!arg) return notify_fail("�п�J�Ʀr�C\n");
        if(sscanf(arg,"%d",x)!=1 )
		return notify_fail("�п�J�Ʀr�C\n");
	if( x < 4 || x > 10 )
		return notify_fail("��J��ƽd��b4~9�����C\n");
	set("num",x);
	game_reset();
	write("��ƭ��] OK�C\n");
	return 1;
}
