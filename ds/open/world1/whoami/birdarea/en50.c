#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"�F�_"NOR"�A�L");
 set("long",@LONG 
�A�C�C������F�_�A�L���`�B�A�H�ۨ�Ǫ���캥�����j,
�o�̪����u�]�V�ӶV�L�z, �C�C�a, �A�o�{�e���N�O�˪L�h�A
��, �V�O���e�i, �@�@���h���O����^��o�޲�.
LONG);
 set("exits",(["west":__DIR__"en51",
               "northeast":__DIR__"en49",
               ]));
 
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

