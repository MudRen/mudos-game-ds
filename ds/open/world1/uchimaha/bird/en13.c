#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");

 set("long",@LONG
�A�{�b�Ө쪰�W�ު�����, �A���b�@�Ӧ��⤣����
�����s�}��, �A�V��`�B���Y�ݤF��, �̵M�������
�����, �b�A���I�ᤣ���B, �i�H�ݨ�@�����G��, ��
�O�A���i�Ӯɪ��J�f.... 
LONG
    );
 
 set("exits",(["northeast":__DIR__"en14",
               "south":__DIR__"en12",
           ]));
 set("no_clean_up", 0);
 setup();
}           
