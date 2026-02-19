// MaxEstLa - Blood Rush - ALL RIGHTS RESERVED 2022-2026


#include "AssetUserDataAccessorLibrary.h"
#include "Interfaces/Interface_AssetUserData.h"

bool UAssetUserDataAccessorLibrary::ImplementsAssetUserData(UObject* Object)
{
	return IsValid(GetUserDataInterface(Object)->_getUObject());
}

void UAssetUserDataAccessorLibrary::AddAssetUserData(UObject* Object, UAssetUserData* AssetUserData)
{
	IInterface_AssetUserData* Interface = GetUserDataInterface(Object);
	if (Interface)
	{
		Interface->AddAssetUserData(AssetUserData);
	}
}

void UAssetUserDataAccessorLibrary::RemoveAssetUserData(UObject* Object, const TSubclassOf<UAssetUserData> AssetUserDataClass)
{
	IInterface_AssetUserData* Interface = GetUserDataInterface(Object);
	if (Interface)
	{
		Interface->RemoveUserDataOfClass(AssetUserDataClass);
	}
}

void UAssetUserDataAccessorLibrary::RemoveAllAssetUserData(UObject* Object)
{
	RemoveAssetUserData(Object,UAssetUserData::StaticClass());
}

bool UAssetUserDataAccessorLibrary::HasAnyAssetUserData(UObject* Object)
{
	const TSubclassOf<UAssetUserData> ParentClass = UAssetUserData::StaticClass();
	UAssetUserData* ReturnValue = nullptr;
	return GetAssetUserDataByClass(Object,ParentClass,ReturnValue);
}

bool UAssetUserDataAccessorLibrary::GetAssetUserDataByClass(UObject* Object, const TSubclassOf<UAssetUserData> Class, UAssetUserData*& AssetUserData)
{
	if (IInterface_AssetUserData* Interface = GetUserDataInterface(Object))
	{
		AssetUserData = Interface->GetAssetUserDataOfClass(Class);
		return IsValid(AssetUserData);
	}
	
	return false;
}

TArray<UAssetUserData*> UAssetUserDataAccessorLibrary::GetAssetUserDataArray(UObject* Object)
{
	if (IInterface_AssetUserData* Interface = GetUserDataInterface(Object))
	{
		const TArray<UAssetUserData*>* AssetUserDataArray = nullptr;
		AssetUserDataArray = Interface->GetAssetUserDataArray();
		return AssetUserDataArray ? *AssetUserDataArray : TArray<UAssetUserData*>();
	}
	
	return TArray<UAssetUserData*>();
}

IInterface_AssetUserData* UAssetUserDataAccessorLibrary::GetUserDataInterface(UObject* Object)
{
	return Cast<IInterface_AssetUserData>(Object);
}
