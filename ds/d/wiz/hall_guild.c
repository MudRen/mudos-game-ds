// Room: /d/wiz/hall2.c
#include <path.h>
inherit ROOM;

void create()
{
 set("short", "¾�~��s��");
 set("long", @LONG
�o�ӥզ⪺�ж��N�O��`�Ův�̤��G�s¾�~�M�j���̵o��s�W�w
���a��A�|�P�\�۳\�h�j�K�d�A�̭����O�Ův�̪���s�߱o���i�A��
���Ӧ���ߪ��Ův���w�g���۷�{�ת��g��P��O�C�ڤ۰ϰ쪺�Ův
�������o��ϰ�~�����Ӧ��ǲߡC�����ϰ쪺�򥻳W�w�P�`�N�ƶ�
�Х� < [1;34mabout guild[m > �d�ߡC���_���|���@�s�ꪺ�ɮv�d�ҡC

  [���B����count���O���Ův����U�ؤ��P�ޯ����שҹ�������O]

LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "down"   : __DIR__"hall_area",
    "up"     : __DIR__"hall_arch",
    "east"   : __DIR__"hall_skill",
    "west"   : __DIR__"hall_spell",
    "north"  : __DIR__"hall_master",
//    "south"   : __DIR__"hall_special",
 ]));

 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/guild_b", "???");
}

void init()
{
 add_action("do_help","about");
 add_action("do_count","count");
}

int do_help(string arg)
{
 if(arg=="guild")
 {
   if( file_size("/doc/wiz/guild.txt")>0 )
   {
    this_player()->start_more( read_file("/doc/wiz/guild.txt") );
    write("\n");
   } else write(" SORRY. �����ɩ|���إ�. \n");
  return 1;
 }
 return 0;
}

int do_count(string arg)
{
	int hard,i,exp_sum=0,money_sum=0;
	if(!arg || sscanf(arg,"%d",hard)!=1) return notify_fail("���O: count <���׭�>�C\n");
	printf("���׭�: %d \n",hard);
	if( hard > 999 || hard < 1) return notify_fail("�Э��]�@��1��999�����׭ȡC\n");
	for(i=1;i<100;i++)
	{
		exp_sum=exp_sum+(i*i*hard/50);
		money_sum=money_sum+(i*i*hard/70);
		if(i%10==0) printf("�ޯ൥��:[%3d] �g��֭p:[%8d]  �ǶO�֭p:[%8d]\n",i,exp_sum,money_sum);
	}
	printf("�ޯ൥��:[ 99] �g��֭p:[%8d]  �ǶO�֭p:[%8d]\n",exp_sum,money_sum);
	return 1;
}