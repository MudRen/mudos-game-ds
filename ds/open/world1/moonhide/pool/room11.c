#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "���H�P�}");
        set("long", @LONG
�����D���j�Ӫ��L���A�ϱo�F�ɸ��b�C��W�O�����ʡA�U��U
���A���X�a��n�X�l�ءA�D�n���۪������������ۡA�b�C�᳡���A
�Y�X�F�@�ڥ۬W�A�P�}�޳��ݬ۳s���A���ӴN�O���}�ު���W�C 
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room13",  
  "east" : __DIR__"room9",
])); 
        set("objects", ([ /*sizeof == 1*/
  __DIR__"npc/small-fish":1,
])); 
         set("item_desc", ([
                "�a�}" : "�@�Ӷ¶ª��}�A�ݨӥi�H�i�h(enter)�C\n",
                ]));
        set("no_clean_up", 0);  
          setup();
}void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
          object me;
          me=this_player();
          if(arg != "�a�}")
            return 0;
          else {
            message_vision("$N���a�}�p�F�U�h�C\n",me);
            me->move("/open/world1/moonhide/pool/test");
            return 1;
          }
}

