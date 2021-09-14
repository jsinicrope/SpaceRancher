// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory_System/Item_Base.h"

// Sets default values
AItem_Base::AItem_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Main_Item_Structure.bIsValidItem = true;
}
