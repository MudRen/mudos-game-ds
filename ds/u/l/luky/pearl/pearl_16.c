// Room: /u/l/luky/room/pearl_16.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"�ï]�_��"NOR);
set("long", @LONG

  �A�����ѹp�����ï]�_��C�_��O����D�n���ө��A�p�G�A�|
���h�l����[1;33m �x       �d�e�f�g�g�g�f�e�d             �x[m �ơA��
���Ӧ���[1;33m   ���d�e�f[m�x�����x�����x�����x[1;33m�f�e�e�d�d�c��[m�߻P��
�L�_�I�� �y �x �ХТx�ХТx�ХТx�ХТx �� �� �x�� �j�k �洫
         �y �x[33m�Ģc�d�e�e�f�f�f�f�f�e�e�d�c��[m  �x   �j�k
�ááááááá� :��  ���� ���� ����  ��: �áááááááá�
:      -         :�y  �_  ������  �_  �j:[1;35m�i�R���˳Ƥ��ߡj[m  :
= ."   -       - :�y  ��[1;34m   �i�i[m   ��  �j:                  =
==-  " -       - :�y[34m       �i�i[m       �j:  -       - .   -==
�ááááááááááááá�  �áááááááááááááá�

LONG
);
set("exits", ([ /* sizeof() == 3 */
"north" : __DIR__"pearl_29",
"west" : __DIR__"pearl_15",
"east" : __DIR__"pearl_17",
]));
set("no_clean_up", 0);
set("light",1);
setup();
load_object(__DIR__"npc/item/greentea");
}
