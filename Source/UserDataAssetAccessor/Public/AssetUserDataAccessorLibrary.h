// MaxEstLa - Blood Rush - ALL RIGHTS RESERVED 2022-2026

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AssetUserDataAccessorLibrary.generated.h"

/**
 * This library allows you to use the Interface_AssetUserData class
 * This interface is not properly implemented in all classes in the engine
 * Please check its implementation prior to using it
 * i.e UActorComponent doesn't implement GetAssetUserDataArray() but implements other methods (WHY???)
 */
UCLASS()
class USERDATAASSETACCESSOR_API UAssetUserDataAccessorLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	public:
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static bool ImplementsAssetUserData(UObject* Object);
	
	UFUNCTION(BlueprintCallable)
	static void AddAssetUserData(UObject* Object, UAssetUserData* AssetUserData);
	
	UFUNCTION(BlueprintCallable)
	static void RemoveAssetUserData(UObject* Object, const TSubclassOf<UAssetUserData> AssetUserDataClass);
	
	UFUNCTION(BlueprintCallable)
	static void RemoveAllAssetUserData(UObject* Object);
	
	UFUNCTION(BlueprintCallable)
	static bool HasAnyAssetUserData(UObject* Object);
	
	UFUNCTION(BlueprintCallable, meta=(DeterminesOutputType="Class", DynamicOutputParam="AssetUserData"))
	static bool GetAssetUserDataByClass(UObject* Object, const TSubclassOf<UAssetUserData> Class, UAssetUserData*& AssetUserData);
	
	UFUNCTION(BlueprintCallable)
	static TArray<UAssetUserData*> GetAssetUserDataArray(UObject* Object);
	
private:
	static IInterface_AssetUserData* GetUserDataInterface(UObject* Object);
};
