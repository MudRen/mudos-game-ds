inherit ITEM;
inherit F_STUDY;

void create()
{
    set_name("���a�M��", "song blade book", "book");
    set_weight(1000);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
         set("no_give",1);
        set("long",@long
�@�@�o�O�@���M�СA�u����������Q�����x�����֯ȡA�C���W����e�ۤM
�ۤι��Ʀr���֤S�������ۦ��ѻ��A�ʭ��W���M�|�Ӥj�r�u���a�M�k�v�C
long
);
        set("required/skill", ([
            "literate" : 50,
        ]));
        set("content", ([
            "song blade" : 20,
        ]));
    }
    setup();
}

