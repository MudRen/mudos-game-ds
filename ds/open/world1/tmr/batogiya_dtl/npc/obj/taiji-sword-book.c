inherit ITEM;
inherit F_STUDY;

void create()
{
    set_name("�ӷ��C��", "taiji-sword book", "book");
    set_weight(1000);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("no_give",1);
        set("long",@long
�@�@�o�O�@���ӷ��C�k���C�СA�ʭ����Ӥӷ����ϥܡC
long
);
        set("required/skill", ([
            "literate" : 110,
        ]));
        set("content", ([
            "taiji-sword" : 10,
        ]));
    }
    setup();
}

