#include <ansi.h>
#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name(HIM"�p�m��",({"Yuan-yang stiletto","stiletto"}) );
        set("long","�@��S�Oű�y���P���A�M�����Ӫ��A�γz�Ů𤣵o�X�@���n�T�C\n"+
        "���`�W��ۨⰦ���V���p�m�A�Q�����R���ҼˡC\n");
          set_weight(500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","��");
              set("value",1500);
              set("limit_dex",25);
        }
              set(HIC"wield_msg","�@�D���ݪ��ť��G�F�@�U�C\n");
          init_dagger(25);
        setup();        
}

