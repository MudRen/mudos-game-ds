inherit ITEM;

void create()
{
    set_name("�H���T���y", "crush-bone axe note", "note");
    set_weight(1000);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
         set("no_give",1);
        set("long",@long
�@�@�o�O�@�������H���T��ۦ������y�A�z�i�H�ǥѾ\Ū�W������r
�βŸ��ӾǱo�u�H���T��v�C
long
);
        set("required/skill", ([
            "literate" : 50,
        ]));
        set("content", ([
            "crush-bone axe" : 20
        ]));
    }
          set("no_give",1);
    setup();
}

