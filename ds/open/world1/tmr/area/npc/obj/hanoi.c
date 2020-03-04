// hanoi (�e����) Edit By Tmr 2000/5/15
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
	set_name("�e����C����",({"hanoi game","game"}) );
	set("long",@long
    �@�x�p�����C�����A��a��K�C�A�i�H�ݨ�C�����W�Y���i�p
�ȱ��A�W�Y�g�ۤ@�ǫ��O�G

.		�d�ݦs���L���T�ڬW�l
record		�d�ݧA�Ҳ��ʪ��O��
reset		���s�}�l
move x y	���� x �W�W����L�� y �W�W�C

long
);
	set_weight(100);
	set("unit","�x");
	set("value",100);
	set("num",3);		//�T�ӽL�l
	game_reset();
	setup();
}

// �C�����]
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
	if(arg==0)	return "��";
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
                return notify_fail("��J�榡�Gmove x y�C\n");
	if( (x!="a" && x!="b" && x!="c")
	 || (y!="a" && y!="b" && y!="c")	 ||  x==y )
	return notify_fail("��J�ѼơA�u��a,b,c �T�ءA�B��ѼƤ���ۦP�C\n");
	if(query("move_ok") ) return notify_fail("�A�w�g���ʦ��\\�A��reset ���]�C���C");
	switch(x) {
	case "a":
		if(ma==0) return notify_fail("A �W�W�w�S���i�Ѳ��ʪ���L�F�C\n");
		switch(y) {
		case "b":
		if(mb==0 ) {
			b[++mb]=a[ma--];
			a[ma+1]=0;
			record +=sprintf("%d : %s -> %s \n",times++,x,y);
			break;
		}
		if (a[ma] > b[mb] ) 
			return notify_fail("���ʥ��ѡGB �W�W����L�p�� A�W�W����L�C\n");
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
			return notify_fail("���ʥ��ѡGC �W�W����L�p�� A�W�W����L�C\n");
		c[++mc]=a[ma--];
		a[ma+1]=0;
		record +=sprintf("%d : %s -> %s \n",times++,x,y);
		break;
		}
	break;
	case "b":
		if(mb==0) return notify_fail("B �W�W�w�S���i�Ѳ��ʪ���L�F�C\n");
		switch(y) {
		case "a":
		if(ma==0 ) {
			a[++ma]=b[mb--];
			b[mb+1]=0;
			record +=sprintf("%d : %s -> %s \n",times++,x,y);
			break;
		}
		if (b[mb] > a[ma] ) 
			return notify_fail("���ʥ��ѡGA �W�W����L�p�� B�W�W����L�C\n");
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
			return notify_fail("���ʥ��ѡGC �W�W����L�p�� B�W�W����L�C\n");
		c[++mc]=b[mb--];
		b[mb+1]=0;
		record +=sprintf("%d : %s -> %s \n",times++,x,y);
		break;
		}
	break;
	case "c":
		if(mc==0) return notify_fail("C �W�W�w�S���i�Ѳ��ʪ���L�F�C\n");
		switch(y) {
		case "a":
		if(ma==0 ) {
			a[++ma]=c[mc--];
			c[mc+1]=0;
		record +=sprintf("%d : %s -> %s \n",times++,x,y);
			break;
		}
		if (c[mc] > a[ma] ) 
			return notify_fail("���ʥ��ѡGA �W�W����L�p�� C�W�W����L�C\n");
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
			return notify_fail("���ʥ��ѡGB �W�W����L�p�� C�W�W����L�C\n");
		b[++mb]=c[mc--];
		c[mc+1]=0;
		record +=sprintf("%d : %s -> %s \n",times++,x,y);
		break;
		}

	break;
	}

          if(mb==num) {
           tell_object(this_player(),HIY "�A���\\�����ʩҦ�����L��B �W�W�I�I\n" NOR);
          set("move_ok",1);
          }

	write("���ʦ��\\�C\n");
        return 1;
}

int do_look()
{
	int i;
	string p="";
	for(i=num;i>0;i--) {
		p +="�@"+replace(a[i]) +"�@"+ replace(b[i]) +"�@"+replace(c[i])+"\n";
	}
	p +=" �@A�@ B  C\n";
	write(p+"\n");
	return 1;
}

int do_show()
{
	write("�A�Ҳ��ʪ��O���G\n");
	write("------------------------------\n");
	write(record+"\n");
	return 1;
}

int do_game_reset()
{
	write("�C����s OK�C\n");
	game_reset();
	return 1;
}

int do_set_num(string arg)
{
        int x;
        if(sscanf(arg,"%d",x)!=1 )
                return notify_fail("�п�J�Ʀr�C\n");
        if( x < 3 || x > 9 )
                return notify_fail("��J��ƽd��b3~9�����C\n");
        set("num",x);
        game_reset();
        write("��L���] OK�C\n");
        return 1;
}
