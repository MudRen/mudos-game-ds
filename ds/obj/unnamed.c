
// �Ψӵ� marry_ring ��
inherit ITEM;

void create()
{
        set_name("���R�W", ({ "unnamed" }));
        set_weight(0);
        setup();
}

int query_restore(string name)
{
        string file;
        if( stringp(file="/data/user/"+ name[0..0] + "/"+ name + ".o"))
                return restore_object(file, 1);
        return 0;
}
