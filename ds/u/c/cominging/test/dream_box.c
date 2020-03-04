#include <ansi2.h>
inherit ITEM;
inherit F_UNIQUE;

string *obj = ({ });
void restore_box_autoload();
void save();
void restore_box_autoload();
void remove() { save(); }

void create()
{
        set_name(BBLU+HIC"�ڤ��_��"NOR, ({ "dream box", "box" }));
        set("long", @LONG
�@�Ӱg�ۦ����_��, �~��˹��ä���򪺵��R, ���O�o�{�X�벴��
���~, �]�\�O�W�����^�O���_��, �]�i��O�_���W�誺���@���ï]
, ����_���e�q�ݰ_�Ӥ��j, ���̭��o�õ۳\�h���K.
LONG
        );
        set("value", 21300);
        set("no_give", 1);
        set("no_sell", 1);
        set("no_drop", 1);
        set("unit", "��");
        set_max_encumbrance(9999999);
        setup();
        restore_box_autoload();
}

void init()
{
        add_action("do_save_o", "sa");
        add_action("do_restore_o", "re");
}

int do_save_o()
{
        save();
        return save_object(__DIR__"dream_box.o", 1);
}

int do_restore_o()
{
        return restore_object(__DIR__"dream_box.o", 1);
}

void save()
{
        object *inv;
        int i, j;
        mixed param;

        inv = all_inventory();
        obj = allocate(sizeof(inv));
        for(i=0, j=0; i<sizeof(inv); i++) {
                if( inv[i]->query_unique() ) continue;
                obj[j] = base_name(inv[i]);
                j++;
        }
        obj = obj[0..j-1];
}

void restore_box_autoload()
{
        int i;
        object ob;
        string file, err;

        restore_object(__DIR__"dream_box.o");

        for(i=0; i<sizeof(obj); i++) {
                file = obj[i];
                err = catch(ob = new(file));
                if( err || !ob ) {
                        write("�Aı�o���G�����F���򭫭n���F��M�̦n�q���@�U�Ův�C\n");
                        write_file(__DIR__"AUTOLOAD", sprintf("Fail to autoload %s of %s, error %s\n",
                                file, this_object()->query("name"), err));
                        continue;
                }
                export_uid(ob);
                ob->move(this_object());
//              if(ob) ob->autoload(param);
        }
}

int query_autoload() { return 1; }
