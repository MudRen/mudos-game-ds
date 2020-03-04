// Room: /u/s/suez/area/hotel_back.c
inherit ROOM;
void create()
{
	set("short", "�a�U�K��");
	set("long", @LONG
�o�̬O���a�U�K�ǡA�R���F�Ǥg�A�A���U�Ӯɨ��W�]�g�ۤF���֡C�J
�Ӭݬݳo�̡A��B���O�ݯ}����²�A���ê��L���A�G�a����۵����C�ݨ�
���G�ܤ[�S���H�ӹL�F�A���L�A���G�b�R�����a���`�������ǳ\����{
�A���D�o�̴��g......�H
LONG
	);

        set("objects",([
              __DIR__"npc/eq/star_robe" : 1,
              ]) );
	setup();
}
void init()
{
        add_action("do_push", "push");
}

int do_push(string arg)
{
        object me;
        me=this_player();
 

        if (arg != "���" && arg !="��" )
                return 0;
        else 
        {
        me->move(__DIR__"base_2");
        tell_room(environment(me),"��W���J���M��ʡI"+me->query("name")+"������ᨫ�F�X�ӡI�I\n",me);
        return 1;
        }
}