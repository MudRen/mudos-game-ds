#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",MAG"�v���q"NOR);
 set("long",@LONG
�A�w�g����F���q�����Y�A���e�����H���A�P��Q����
��Y�A���Χ������ڤF�@������I�ӯ��ΤW�����ɦ��A����
��O�աA�ѥͿO�աA ...�۵M�O�@�ˤ��ʡA���O�b���Ϊ���
�߫o�d�X�F�@�ӵ٧Ϊ��Ů�A�ݰ_�Ӯ�~���f.....
LONG
    );
 set("exits",([   "west":__DIR__"ten43",
    ]));
 set("objects", ([__DIR__"npc/cw_taoist" : 1,
    ]));
set("item_desc",([
        "�٧ΪŮ�" : CYN"�A�o�{�b�Ů椧�����@�T����....?!\n"NOR,
      "����" : CYN"�o�ӻ����O�s�b���Τ��W��, �A�S����k�⥦���U, ���L�������γB�s���O...?\n"NOR,
]));
set("no_clean_up",0);
set("light",1);
 setup();
}

void init()
{
        add_action("do_pray","pray");
}

int do_pray(string arg)
{
        object me,where1;
        string a;
        me = this_player();
        where1 = load_object(__DIR__"ten45");
        if( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
        if( me->is_fighting() )
                return notify_fail("�A�٦b�԰����A�S���ťh���o�بơI\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("�A�n��������?\n");
        if( a!="����" )
                return notify_fail("���o�تF���?\n");
      if (me->query("level") > 25)
     {
        message_vision(HIW"$N�ۤߪ����U��������, ���M�@�}�����ƹL, $N���h�F�ܼv! \n"NOR,me);
          me->move(where1);
        return 1;
     }
     else 
     {
        message_vision(HIW"$N�ۤߪ����U��������.... \n"NOR,me);
        return 1;
     }

}


