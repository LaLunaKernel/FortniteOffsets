static auto getsocketlocation(uintptr_t skeletal_mesh, int bone_index) -> fvector {
		uintptr_t bone_array = read<uintptr_t>(skeletal_mesh + offsets::BoneArray);
		if (bone_array == NULL) bone_array = read<uintptr_t>(skeletal_mesh + offsets::BoneArray + 0x10);

		FTransform bone = io->read<FTransform>(bone_array + (bone_index * 0x60));
		FTransform component_to_world = read<FTransform>(skeletal_mesh + offsets::ComponentToWorld);
		D3DMATRIX matrix = matrix_multiplication(bone.to_matrix_with_scale(), component_to_world.to_matrix_with_scale());

		return fvector(matrix._41, matrix._42, matrix._43);
	}
