#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"�F�_"NOR"�A�L");
 set("long",@LONG
�A�a�ۤ��w�������e���F�ƤQ�B, �h��X�G�w�g���A���h�F
�e�������u, �P�ɤ]�o�{�a�W���ǳ\�d�g. �b�o�̧A�ݨ�@�ӫD
�`�ݯ}���i�ܵP, �]�\�O�g�L���a�����I�a�ҥߪ�.
LONG);
 set("item_desc",([
        "�i�ܵP":"�A���̭����N�O�F�_�A�L���·t�a�a�F�C\n",
     ]));
 set("exits",(["east":__DIR__"en50",
               "south":__DIR__"en53",
               ]));
 
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

