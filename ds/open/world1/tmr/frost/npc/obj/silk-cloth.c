inherit ITEM;

void create()
{
        set_name("���S", ({ "silk cloth","cloth","_SILK_CLOTH_" }));
        set("long",@LONG
�o�O�@���k���H����a�����S�A���ѲH�H���᭻���C
LONG
        );
        set_weight(50);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
        }
          set("value",0);
    setup();
}


