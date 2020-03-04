//Edit By Tmr 2000/5/9
// V1.0

#include <ansi.h>
#define INDEX "  0 1 2 3 4 5 6 7 8 9"
inherit ITEM;

int score=0,total=0,max=0;
int game_reset();
int show();
int run_map(int x,int y,int arg);
int set_map();
string replace(int arg);

void create()
{
	set_name("�x�W�C����",({"hand game","game"}) );
	set("long",@long
�ڤۤC��Ĥ@���u�W�C�����ɱM�ξ��ءC
    �@�x�p�����C�����A��a��K�C�A�i�H�ݨ�C�����W�Y���i�p
�ȱ��A�W�Y�g�ۤ@�ǫ��O�G

.		�[�ݹC���e��
gsc		��ݧA�ұo������
reset		���s�}�l
input x y	��J�y��
hsc		�d�ݧA���̰�����

�C�����k�G��A�I��@�Ӧ���ɡA��F��ۦP�C�⪺����A�|�v�@�����A
          �ӥB�|�̤@���Ү������ӼơA�ӼW�[���ơC
          �����������A�|�V���a�C��@�Ӿ�ƥ���������A�|�V�W�a�C
long
);
	set_weight(100);
	set("unit","�x");
	set("value",100);
	game_reset();
	setup();
}

mixed *a=allocate(10);
string replace(int i)
{
	string word;
	switch(i)	{
	case 0:	word=    "  ";			break;
	case 1:	word=HIG "��" NOR;		break;
	case 2:	word=HIM "��" NOR;		break;
	case 3:	word=HIB "��" NOR;		break;
	case 4:	word=HIW "��" NOR;		break;
	case 5:	word=HIC "��" NOR;		break;
	case 6:	word=HIR "��" NOR;		break;
	}

	return word;
}

int game_reset()
{
	int i,j;
	for (i=0;i<sizeof(a);i++) {
		a[i]=allocate(10);
		for (j=0;j<sizeof(a[i]);j++) {
			a[i][j]=1+random(6);
		}
	}
}

int show()
{
	int i,j;
	string pp;
	pp=HIW INDEX +"\n"NOR;
	for (i=0;i<sizeof(a);i++) {
		pp +=HIW +(string)i+" "NOR;
		for (j=0;j<sizeof(a[i]);j++) {
			pp +=replace(a[i][j]);
		}
		pp+="\n";
	}
	pp+=HIW INDEX +"\n"NOR;
	tell_object(this_player(),pp+"\n\n�ثe�o���G"+score+"\n");
	return 1;
}

int run_map(int x,int y,int c)
{
	int i,j,k;
	if(x < 0 || x > 9 || y < 0 || y > 9 )	return 1;
	if( a[x][y]==c ) {
		a[x][y]=0;
		max+=1;
		total += 1;
		run_map(x+1,y,c);
		run_map(x-1,y,c);
		run_map(x,y+1,c);
		run_map(x,y-1,c);
	}
	else
		return 1;
}

int set_map()
{
	int i,j,x,y,flag;
	mixed *b=allocate(10);
	for(i=0;i<sizeof(b);i++) {
		b[i]=allocate(10);
	}
	x=0;	y=0;
	for(i=0;i<sizeof(a);i++) {
		y=0;
		if(flag==1) x+=1;
		flag=0;
		for(j=0;j < sizeof(a[0]);j++) {
			if(a[i][j] !=0 )	{
				flag=1;
				b[x][y]=a[i][j];
				y+=1;	
			}
		}
	}
	//�����
	score +=max*max;
	max=0;
	a=b;
	return 1;
}

void init()
{
	add_action("do_look",".");
	add_action("do_reset","reset");
	add_action("do_input","input");
	add_action("high_score","hsc");
}
int high_score()
{
	int sc;
	sc=this_player()->query("game_score");
	if(!sc)
		return notify_fail("�A��ثe�A���S���O���L���ơC\n");
	tell_object(this_player(),HIY"�A���C���̰����G "+(string)sc+" �C\n"NOR);
	return 1;	

}

int do_reset()
{
	int hsc;
	hsc=this_player()->query("game_score");
    if(score > hsc)     this_player()->set("game_score",score);
	score = 0;
	total = 0;
	max = 0;
	game_reset();
	write("��s�C��Ok�C\n");
	return 1;
}

int do_look()
{
	show();
	return 1;
}

int do_input(string arg)
{
	int x,y,c;
	if(!arg )
		return notify_fail("���O�榡�Ginput x y (���y�� ��y��)�C\n");
	if(sscanf(arg,"%d %d",x,y)!=2 )
		return notify_fail("���O�榡�Ginput x y (���y�� ��y��)�C\n");
	if(x < 0 || x > 9 || y < 0 || y > 9)
		return notify_fail("��J���y�Хu�b0~9�����C\n");
	if(a[x][y]==0 )
		return notify_fail("�o�Ӧ�m�èS���i�H�I�諸����C\n");
	c=a[x][y];
	if( (y < 9 && c==a[x][y+1] )
	||  (y > 0 && c==a[x][y-1] )
	||  (x < 9 && c==a[x+1][y] )
	||  (x > 0 && c==a[x-1][y] ) 	) {
		run_map(x,y,c);
		set_map();
		show();
		if(total==100) {
			write("���ߧA�����������Ҧ�����C(�A�����ƼW�[�@���C)\n");		
			score*=2;
		}
	}
	else return notify_fail("�A���I�諸�o�����L�ġC\n");
	return 1;
}
