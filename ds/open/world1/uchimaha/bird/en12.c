#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");

 set("long",@LONG
�A�{�b�Ө쪰�W�ު�����, �A�~���i�o�ӥ޸�, 
�A�N�Q��{���d�o�֭n�R�X�ӤF, �A��F��|�P, �A�o
�{�o�̹�b�ܴc��, ��B���O����(corpse), �����O��
����, �s�H������, �Aı�o�٬O���I���a�C
 
LONG
    );
 set("item_desc",([
        "corpse":"�A�³o�����ݤF��, �o�{�W�����Q���j������������,
          
�A���Ĥ��Pı�o�A�U�h�@�w�|���M�I!!\n",
     ]));
 set("exits",(["north":__DIR__"en13",
               "south":__DIR__"en11",
           ]));
 
 set("no_clean_up", 0);
 setup();
}           
