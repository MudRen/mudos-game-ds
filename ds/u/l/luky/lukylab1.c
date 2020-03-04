// Room: /u/l/luky/room/pearl_16.c
#include <ansi.h>
inherit ROOM;
inherit MOBROOM;	//�ݩ�b inherit ROOM; ����
void create()
{
	set("short", HIG"�s���Ĥ@�����"NOR);
	set("long", @LONG

  �A�����ѹp�����ï]�_��C�_��O����D�n���ө��A�p�G�A�|
���h�l����[1;33m �x       �d�e�f�g�g�g�f�e�d             �x[m �ơA��
���Ӧ���[1;33m   ���d�e�f[m�x�����x�����x�����x[1;33m�f�e�e�d�d�c��[m�߻P��
�L�_�I�� �y �x �ХТx�ХТx�ХТx�ХТx �� �� �x�� �j�k �洫
         �y �x[33m�Ģc�d�e�e�f�f�f�f�f�e�e�d�c��[m  �x   �j�k
�ááááááá� :��  ���� ���� ����  ��: �áááááááá�
:      -         :�y  �_  ������  �_  �j:[1;35m�i�˳ƥ洫���ߡj[m  :
= ."   -       - :�y  ��[1;34m   �i�i[m   ��  �j:                  =
==-  " -       - :�y[34m       �i�i[m       �j:  -       - .   -==
�ááááááááááááá�  �áááááááááááááá�

LONG
	);
set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lukylab2",
  "east" : __DIR__"workroom1",
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