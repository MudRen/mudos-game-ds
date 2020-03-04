#include <ansi.h>
        
inherit ITEM;

void create()
{
    set_name("�����q��", ({"mercury lode", "lode"}));
    if( !clonep() ) {
        set("long", @LONG
�����q�O�ؤ�����٬öQ�����ݡA���ƶq�]�D�`�}���C
�ӳo�ӯ����q�ߥi�H����(dig)�X�����q�A���L�A��M
�o�������K�S����C
LONG
);
        set("value", 10000);
          set("no_steal",1);
        set("unit", "�y");
        set("weight", 1000000);
        set("no_get",1);
      } else
        set_default_object(__FILE__);
    setup();
}

void init()
{
        add_action("do_dig", "dig");
}

int do_dig(string arg) {

        object hoe;
        object mercury, me;

        me = this_player();
        if( me->is_busy())
                return notify_fail("�A�����ۡC\n"); 
        if( !arg )
                return notify_fail("�A�Q�n��������H\n"); 
        if( arg != "lode" && arg != "�����q��" ) 
                return notify_fail("�A�L�k�����o�˪F��C\n"); 

        hoe = present("_IRON_HOE_", me);
        if( !objectp(hoe) )
                return notify_fail("�A���W�S���i�H�����q�ߪ��u��C\n");
        
        switch( random(4) ) {
                case 0:
                        message_vision( YEL "$N"YEL"���_�K�S���$n"YEL"�V�V�����A���F�b�ѡA�ש���X�@�����ȡC\n" NOR, me, this_object());        
                        mercury = new(__DIR__"mercury-mine");
                        mercury->move( me );
                        add("times",1);
                        break;
                case 1:
                        message_vision( YEL "$N"YEL"���_�K�S���$n"YEL"�V�V�����A���F�b�ѡA����]�S���C\n" NOR, me, this_object() );        
                        break;
                default:
                        message_vision( YEL "$N"YEL"���_�K�S���$n"YEL"�V�V�����A�y�F�������A����]�S���C\n" NOR, me, this_object() );        
                        break;
        }

        me->start_busy(2);

        if( query("times" ) > 3 + random(6) ) {
                message_vision( HIW "$n"HIW"���q���w�g�\\�ܤF�C\n" NOR, me, this_object() );
                destruct( this_object() );
        }
        return 1;
}
