#include <ansi.h>
inherit ROOM;
void show(object me);
void create()
{
        set("short", HIG"��g�Z��"NOR);
        set("long",
"�o�̬O�@���ܯ䪺�Z��..�A�o���ְk�]�~�棬..\n"
"�A��M�ݨ차��̦��@��"HIY"�����{�{"NOR"���F��...\n"

);
        set("exits", ([ /* sizeof() == 2 */
        "east" : __DIR__"workroom3",
        ]));
        set("item_desc",([
        "��g����":"�@�ӫܯ䪺����,���G�ܤ[�S�R���ˤl��A�ݨ�̭����@�Ӫ����{�{���F��,���A�Ԥ���Q��(dig)�X�ӡC\n",
        "��g������s":"�ѩ�o�̹�b�ӯ�F��A�Ԥ���Q��(push)�U�R��(���s)�C\n",
        ]) );
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall",1);
        set("no_kill",1);
        setup();
}
void init()
{
  object me;
  ::init();
  if( interactive(me = this_player()) && !me->is_fighting())
 {
  remove_call_out("hi");
  call_out("hi",1,me);
  }
  add_action("do_push","push");
  add_action("do_dig","dig");
}
void hi(object me)
{
message_vision(HIC"������"HIY + me->name(1) + NOR""HIC"�j�j�A���|�L�차��W����..�n�ޣ�.^^\n"NOR,me);
tell_object(this_player(),HIR"�A��M�����������F�_��..�n��������g�F..�C\n"NOR);
return;
}
int do_push(string arg)
{
        object me;
        me=this_player();
        if (!arg || arg!="���s") return 0;
        message_vision(HIY"$N���Y��M�Q�l�차���,�n�ޣ��I�C\n"NOR,me);
        me->delete_temp("the-shit");
        me->move(__DIR__"shit");
        me->start_busy(4);
        call_out("flop",3,me);
        return 1;
}
void flop(object me)
{
        if(!me) return;
        if (me->query_temp("fly-sky")==1) return 0;
         tell_object(me,HIC"�A�q�ѪŮ�F�U�ӡA�������O����˿����A�u���������ߪ��C\n");
        me->move("/d/wiz/hall1");
        tell_room(environment(me),me->query("name")+"�q�ѪŮ�F�U�ӡA�������O����˿����A�u���������ߪ��C\n"NOR,me);
        return;
}
int do_dig(string arg)
{
        object me,toy;
        me = this_player();
        toy = new(__DIR__"gold_shit");
        if( !arg ) return 0;
        if( arg!="��g����" && arg!="����" ) return 0;
if( query_temp("digshit") )
{
    return 0;
}
        message_vision(HIC"$N���R�����ۧ�g����,���o�����O���C\n"NOR,me);
        message_vision(HIY"$N�ש�b�̯䪺���h���X�F�@�b�����K�K,�y���T�]���F�_�ӡC\n"NOR,me);
        toy->move(me);
        set_temp("digshit",1);
        this_object()->delete("item_desc");
        set("long",@LONG
�o�̬O�@���ܯ䪺�Z��..�A�o���ְk�]�~�棬..
LONG
        );
        call_out("delay",180,this_object());
        return 1;
        set("item_desc",([
        "��g����":"�@�ӫܯ䪺����,���G�ܤ[�S�R���ˤl��C\n",
        "��g������s":"�ѩ�o�̹�b�ӯ�F��A�Ԥ���Q��(push)�U�R��(���s)�C\n",
]));
}
void delay(object room)
{
        delete_temp("digshit");
        set("long",@LONG
�o�̬O�@���ܯ䪺�Z��..�A�o���ְk�]�~�棬..
LONG
        );
        set("item_desc",([
  "��g����":"�@�ӫܯ䪺����,���G�ܤ[�S�R���ˤl��A�ݨ�̭����@�Ӫ����{�{���F��,���A�Ԥ���Q��(dig)�X�ӡC\n",
  "��g������s":"�ѩ�o�̹�b�ӯ�F��A�Ԥ���Q��(push)�U�R��(���s)�C\n",
]));
        return;
}



