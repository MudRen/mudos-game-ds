//�� /std/item/game_gift.c �гy by -Acme-

#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create()
{
        set_name( "[0;1;33m�[1m�[1m�[1m�[1m�[1m@[1m�[1m�[0m", ({ "war hands","hands" }) );
        set_weight(2276);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�۶Ǭ��W�j�ɥN�ԯ��E�׿�d���@��,�Q���s���c�M��");
                set("unit", "��");
                set("value",2829);
        }
//        set("armor_prop/shield", 3); ->�令bar 1,-alick, �garea���y
        set("armor_prop/bar", 1);
        setup();
}
int query_autoload() { return 1; }

void init()
{
 add_action("do_rename","rename");
 add_action("do_re_eng_name","re_eng_name");
}

int do_re_eng_name(string arg)
{
        string n_who,id,name;
        object me;
        me = this_player();
        if(!arg || sscanf(arg,"%s as %s %s",n_who,name,id )!=3 )
                return notify_fail("��W�榡: re_eng_name <���~> as <�^����W> <�^��²��>.\n");
        if( !present(n_who,me) )
                return notify_fail("�A���W�S���o�ӪF��. \n");
        if( strlen(id) > 10 || strlen(name) > 20 )
                return notify_fail("�Ч�W�r���o�u�@�I, �T�G�@�I.\n");
        message_vision("$N��$n���^��W�r�אּ�i"+name+NOR+"("+id+")�j\n",me,this_object());
        me->set("millennium_armor/id",id);
        me->set("millennium_armor/full_id",name);
      
}



int do_rename(string arg)
{
        string n_who,cname,oldname;
        object me;
        me = this_player();
        oldname = this_object()->query("name");
        if(!arg || sscanf(arg,"%s as %s",n_who,cname)!=2 )
                return notify_fail("��W�榡: rename <���~> as <����W��>.\n");
        if( !present(n_who,me) )
                return notify_fail("�A���W�S���o�ӪF��. \n");
        if( strlen(cname) > 100 )
                return notify_fail("�Ч�W�r���o�u�@�I, �T�q�@�I.\n");
        arg = replace_string(arg, "$BLK$", BLK);
        cname = replace_string(cname, "$RED$", RED);
        cname = replace_string(cname, "$GRN$", GRN);
        cname = replace_string(cname, "$YEL$", YEL);
        cname = replace_string(cname, "$BLU$", BLU);
        cname = replace_string(cname, "$MAG$", MAG);
        cname = replace_string(cname, "$CYN$", CYN);
        cname = replace_string(cname, "$WHT$", WHT);
        cname = replace_string(cname, "$HIR$", HIR);
        cname = replace_string(cname, "$HIG$", HIG);
        cname = replace_string(cname, "$HIY$", HIY);
        cname = replace_string(cname, "$HIB$", HIB);
        cname = replace_string(cname, "$HIM$", HIM);
        cname = replace_string(cname, "$HIC$", HIC);
        cname = replace_string(cname, "$HIW$", HIW);
        cname = replace_string(cname, "$NOR$", NOR);

        me->set("millennium_armor/cname",cname);
        return 1;
}

