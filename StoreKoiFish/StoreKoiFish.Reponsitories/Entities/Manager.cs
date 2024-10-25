using System;
using System.Collections.Generic;

namespace StoreKoiFish.Reponsitories.Entities;

public partial class Manager
{
    public int ManagerId { get; set; }

    public string? Name { get; set; }

    public string? Email { get; set; }

    public string? Phone { get; set; }

    public DateTime? HireDate { get; set; }

    public string? Role { get; set; }

    public virtual ICollection<Staff> Staff { get; set; } = new List<Staff>();
}
