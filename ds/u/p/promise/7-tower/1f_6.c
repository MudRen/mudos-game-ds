#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIC"�R�߷���"NOR);
        set("long", @LONG
�@���J���󤺡A�K�i�Pı��@�Ѳ��Y���𮧱q���Y���X�A��Ǫ�
�J�����G�b���޵ۤ�������A�b�Ǧ�����}�O�A�@�B�G�ۡA���@�B�h
�����A��������ηN�C
LONG);
        
        set("no_recall", 1); 
        set("no_quit",1);       
        set("item_desc",([
     "�}�O": HIW"\n���}�O���G�ܤ[�S���I�U(fire)�F�H\n"NOR,
        ]));
         set("objects", ([ /* sizeof() == 1 */
          __DIR__"lamp" : 1,
        ]));
        set("world", "past");
        set("no_clean_up", 0);
        set("light",0);

        setup();
}  

