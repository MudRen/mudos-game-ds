#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","�˪L");
        set("long", @LONG
�o�O�@���˪L�A�b�A���e�i�ݨ��@���˪١A�˪ٳĤ��ӫءA�˪�
�|�P�A�Ѥ��ӥ~�A�������Ǧa�A�G�m�ۤT�h�˳]�A���h�O�Q�G���M�V
���ۡA�����O�G�Q���������Τ覡�A�Ƹm�����ϡA�̥~��h�O�A�{
�b���B����m�A���ۼƦʮ�ѤѦ˪L�C
LONG
            );
        set("item_desc", ([ /* sizeof() == 1 */
          "�����" : "�o�����ϱƦC����A���o�Φ��_���L�񪺰}�աA�A�i(jump)�W�ϡC\n",
          "����" : "�o�������A�۷��A���n�a��o�Q���x���C\n",
        ]));
set("exits", ([
  "south" : __DIR__"p8",
]));
        set("light",1);
        setup();
}
void init()
{ 
  add_action("do_jump","jump");
}
int do_jump(string arg)
{
          object me;
          me=this_player();
          if(arg!="�����") return 0;
          message_vision("$N�@����A�������D�W�F�����ϡC\n",me);
          me->move(__DIR__"may3");
          return 1;
}
