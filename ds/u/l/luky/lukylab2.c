// Room: /u/l/luky/room/pearl_17.c
#include <ansi.h>
inherit ROOM;
inherit MOBROOM;	//�ݩ�b inherit ROOM; ����
void create()
{
	set("short", HIG"�s���ĤG�����"NOR);
	set("long", @LONG

[1;31m                                     �d�d�d�d�d�d�d�d
                                   �y[41m�i�i�i�i�i�i�i�i[40m�j[m
�ġġġġ�   �A�����b���x���j��W�C��[30;47m���ݡݡݡݡݡ���[m�ġġ�
"  .   -   �\�h��a���~���H�b�o�̻E  [30;47m��[35m �۰ʳc���[30m ��[m     "
:      -   �|��ѡC�A�ݨ�F�䦳�@��  [30;47m���ݡݡݡݡݡ���[m  "  :
= ."   -   �j�Фl�A�H�ӤH�����n����  [30;47m����������������[m     =
==-  " -   �x�C���䦳�@�x�۰ʳc���  [30;47m����������������[m   -==
�áááá� �C                      ��[30;47m��[32mInsert coins[30m��[m�áá�
                                     [30;47m�ࢤ������������[m


LONG
	);
set("objects",([
// __DIR__"automat":1,
]));
set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lukylab1",
]));
set("item_desc",([
  "automat":"�@�x�|���ҥΪ��۰ʳc����C\n",
  "�۰ʳc���":"�@�x�|���ҥΪ��۰ʳc����C\n",
]));
	set("no_clean_up", 0);
	set("light",1);
	set("chance",50);	//�h�� 50% �����v�|�X�{�Ǫ�.
	set("mob_amount",3);	//�h�̦h�X�{�T�өǪ�.
	set("mob_object",({	//�]�w�Ǫ��ɦW.
	"/open/world2/anfernee/start/npc/bug",
	"/u/l/luky/npc/mosquito"
	}) );
	setup();
	
	//�`�N, �~��MOBROOM�� �����i�H�� replace_program(ROOM);
}

void init()
{
        ::init();	//�`�N, �Y�O���~��MOBROOM��room�n�Ψ�init(),�h�ݥ[�o�@��!!

        add_action("d_creat","creat");
        add_action("d_stop","stop");
}

int d_stop(string arg)
{
 this_object()->set_temp("stop_creat",1);
 tell_object(this_player(),"�Ǫ��a�p�w����!\n");
 return 1;
}

int d_creat(string arg)
{
 this_object()->set_temp("stop_creat",0);
 tell_object(this_player(),"�Ǫ��a�p�w�}��!\n");
 return 1;
}